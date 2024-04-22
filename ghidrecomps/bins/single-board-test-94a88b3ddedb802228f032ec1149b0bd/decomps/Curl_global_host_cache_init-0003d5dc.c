
int Curl_global_host_cache_init(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_0003d608;
  if (*(int *)(DAT_0003d608 + 0x18) == 0) {
    iVar2 = Curl_hash_init(DAT_0003d608,7,DAT_0003d610,DAT_0003d614,DAT_0003d60c);
    if (iVar2 == 0) {
      *(undefined4 *)(iVar1 + 0x18) = 1;
      iVar1 = DAT_0003d608;
    }
    else {
      iVar1 = 0;
    }
  }
  return iVar1;
}

