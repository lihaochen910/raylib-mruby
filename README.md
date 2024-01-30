# raylib-mruby
A raylib mruby binding.
It uses the libclang library to parse the raylib header file and generate binding code.

### CodeGenerator.CLI Usage
Code:
```shell
PS CodeGenerator.CLI\bin\Debug\net8.0> .\CodeGenerator.CLI.exe "D:\GitWorkspace\raylib\src" "D:\GitWorkspace\raylib-mruby\projects\CodeGenerator\CodeGenerator.CLI\bin\Debug\net8.0\rMRuby.c"
```

### Dependencies
* dotnet 8
* libclang.runtime
* libclangsharp.runtime
