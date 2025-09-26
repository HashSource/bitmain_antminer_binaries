
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

DSO_METHOD * DSO_METHOD_dlfcn(void)

{
  return (DSO_METHOD *)&dso_meth_dlfcn;
}

