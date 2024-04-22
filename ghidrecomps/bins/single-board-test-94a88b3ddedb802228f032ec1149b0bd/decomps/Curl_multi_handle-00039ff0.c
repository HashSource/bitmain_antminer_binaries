
undefined4 * Curl_multi_handle(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar1 = (undefined4 *)(**DAT_0003a0c8)(1,0xc4);
  puVar3 = puVar1;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0xbab1e;
    iVar2 = Curl_mk_dnscache(puVar1 + 0xb);
    if (iVar2 == 0) {
      iVar2 = Curl_hash_init(puVar1 + 0x12,param_1,DAT_0003a0d0,DAT_0003a0d4,DAT_0003a0cc);
      if ((iVar2 == 0) && (iVar2 = Curl_conncache_init(puVar1 + 0x1a,param_2), iVar2 == 0)) {
        iVar2 = Curl_llist_alloc(DAT_0003a0d8);
        puVar1[5] = iVar2;
        if (iVar2 != 0) {
          iVar2 = Curl_llist_alloc(DAT_0003a0d8);
          puVar1[6] = iVar2;
          if (iVar2 != 0) {
            iVar2 = curl_easy_init();
            puVar1[0x24] = iVar2;
            if (iVar2 != 0) {
              *(undefined4 **)(iVar2 + 0x40) = puVar1;
              *(undefined4 **)(iVar2 + 0x580) = puVar1 + 0x1a;
              puVar1[0x28] = 5;
              puVar1[0x25] = 0xffffffff;
              return puVar1;
            }
          }
        }
      }
    }
    Curl_hash_destroy(puVar1 + 0x12);
    Curl_hash_destroy(puVar1 + 0xb);
    Curl_conncache_destroy(puVar1 + 0x1a);
    Curl_close(puVar1[0x24]);
    puVar1[0x24] = 0;
    Curl_llist_destroy(puVar1[5],0);
    Curl_llist_destroy(puVar1[6],0);
    puVar3 = (undefined4 *)0x0;
    (**DAT_0003a0dc)(puVar1);
  }
  return puVar3;
}

