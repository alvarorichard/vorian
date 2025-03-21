-- xmake.lua

set_project("vorian")

-- Definindo o compilador e as flags
set_toolchains("clang", { cxflags = "-std=c++23 -g -O3 -Wall -Wextra -fsanitize=address" })

-- Definindo a configuração de compilação
target("vorian")
    set_kind("binary")
    add_files("*.cpp")
    add_includedirs(".")

-- Limpando arquivos
task("clean")
    on_run(function ()
        os.rm("*.o")
        os.rm("a.out")
    end)
