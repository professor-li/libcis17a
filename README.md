# libcis17a

A common library used in CIS-17A course.

Initialize bdep:

```powershell
> rm -r -fo .bdep
> rm -r -fo ../libcis17a-debug
> bdep init -C ..\libcis17a-debug @debug cc `
  "config.cxx=cl /MDd"                  `
  "config.cc.coptions=/Od /Zi"          `
  config.cc.loptions=/DEBUG
```
