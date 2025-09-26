
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

FILE * openssl_fopen(char *__filename,char *__modes)

{
  FILE *pFVar1;
  
  pFVar1 = fopen64(__filename,__modes);
  return pFVar1;
}

