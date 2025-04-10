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
