
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

COMP_METHOD * COMP_zlib(void)

{
  return (COMP_METHOD *)&zlib_method_nozlib;
}

