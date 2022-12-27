# SWIG

## Structure of the Python package

We want the Python package to be organized with extensions :

```
pyDSP/
├── core/
│   ├── module
│   ├── parameter
│   ├── config
│   └── ...
├── audio/
│   ├── vad
│   └── ...
├── sdr/
└── cv/
```

For this :

- interface files are included in the parent folder
- setup scripts : https://docs.python.org/3/distutils/setupscript.html
  
## Checking symbols in .so file

```shell
nm --demangle --dynamic --defined-only --extern-only
```

About :

- "U" means the symbol is undefined;
- "T" means the symbol was found in Text section of the code;
- "N" means the symbol is a debugging symbol;
- "W" means the symbol is a weak symbol that has not been specifically tagged as a weak object symbol. When a weak defined symbol is linked with a normal defined symbol, the normal defined symbol is used with no error.

## Useful links

- swig and python extensions : https://stackoverflow.com/questions/12369131/swig-and-python3-surplus-underscore

## Check the contents of a wheel file

```shell
unzip -l dist/package.whl
```
