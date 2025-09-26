
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

hostent * gethostbyname(char *__name)

{
  hostent *phVar1;
  
  phVar1 = gethostbyname(__name);
  return phVar1;
}

