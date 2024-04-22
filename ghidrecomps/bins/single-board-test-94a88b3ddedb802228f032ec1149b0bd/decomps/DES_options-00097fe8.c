
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * DES_options(void)

{
  int *piVar1;
  
  piVar1 = DAT_00098014;
  if (*DAT_00098014 != 0) {
    BIO_snprintf(DAT_00098028,0x20,DAT_0009802c,DAT_00098024,DAT_00098018,DAT_0009801c,DAT_00098020)
    ;
    *piVar1 = 0;
  }
  return DAT_00098028;
}

