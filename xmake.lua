set_project("vorian")

-- Definindo o compilador e as flags
set_toolchains("clang", { cxflags = "-std=c++23 -g -O3 -Wall -Wextra -fsanitize=address" })

-- Configurando o alvo de compilação
target("vorian")
    set_kind("binary")
    add_files("src/*.cpp")
    add_includedirs("include")

-- Tarefa para limpar arquivos gerados
task("clean")
    on_run(function ()
        os.rm("*.o")
        os.rm("a.out")
        os.rm("build")
    end)


task("infer")
    set_menu { usage = "xmake infer", description = "Run Facebook Infer" }
    on_run(function ()
        os.exec("xmake project -k compile_commands")   -- cria ./compile_commands.json

        local cpus = (os.cpuinfo and os.cpuinfo().ncpu) or 1
        os.exec(string.format(
            "infer run --compilation-database compile_commands.json "
          .. "--headers --jobs %d", cpus))
    end)



task("cppcheck")
    set_menu { usage = "xmake cppcheck", description = "Run Cppcheck" }

    on_run(function ()
        os.exec("xmake project -k compile_commands")  -- garante o DB

        local flags = {
            "--project=compile_commands.json",
            "--std=c++23",
            "--enable=all",
            "--inconclusive",
            "--suppress=missingIncludeSystem",  -- <-- aqui
            "--quiet",
            "--xml",
            "--output-file=cppcheck-report.xml"
        }

        os.exec("cppcheck " .. table.concat(flags, " "))
        print("✓ cppcheck concluído → cppcheck-report.xml")
    end)
