
int tls1_set_curves_list(undefined4 *param_1,int *param_2,char *param_3)

{
  uint uVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  undefined1 *ptr;
  uint uVar5;
  uint uVar6;
  int num;
  uint uVar7;
  undefined1 *puVar8;
  undefined1 auStack_a0 [4];
  int local_9c;
  undefined4 local_98 [29];
  
  local_9c = 0;
  iVar4 = CONF_parse_list(param_3,0x3a,1,(list_cb *)0x7025d,&local_9c);
  iVar3 = local_9c;
  if ((iVar4 != 0) && (iVar4 = 1, param_1 != (undefined4 *)0x0)) {
    num = local_9c << 1;
    ptr = (undefined1 *)CRYPTO_malloc(num,"t1_lib.c",0x283);
    if (ptr == (undefined1 *)0x0) {
LAB_00070b50:
      iVar4 = 0;
    }
    else {
      if (iVar3 != 0) {
        uVar7 = 0;
        iVar4 = 0;
        puVar8 = auStack_a0;
        puVar2 = ptr;
        do {
          iVar4 = iVar4 + 1;
          uVar5 = tls1_ec_nid2curve_id(*(undefined4 *)(puVar8 + 8));
          uVar6 = 1 << (uVar5 & 0xff);
          if ((uVar5 == 0) || (uVar1 = uVar6 & uVar7, uVar7 = uVar7 | uVar6, uVar1 != 0)) {
            CRYPTO_free(ptr);
            goto LAB_00070b50;
          }
          *puVar2 = (char)(uVar5 >> 8);
          puVar2[1] = (char)uVar5;
          puVar8 = puVar8 + 4;
          puVar2 = puVar2 + 2;
        } while (iVar4 != iVar3);
      }
      if ((void *)*param_1 != (void *)0x0) {
        CRYPTO_free((void *)*param_1);
      }
      iVar4 = 1;
      *param_1 = ptr;
      *param_2 = num;
    }
  }
  return iVar4;
}

