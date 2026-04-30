# Simple Kernel Module for FreeBSD

Does the following:

1. Sets Event handler
2. Accepts two events: MOD_LOAD and MOD_UNLOAD
3. All other events are ignored with EOPNOTSUPP 

## How to Build

```
make clean
make
```

## Documentation to read

```
man 9 module
```
