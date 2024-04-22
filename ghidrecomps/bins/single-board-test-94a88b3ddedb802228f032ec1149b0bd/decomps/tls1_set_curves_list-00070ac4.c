
int tls1_set_curves_list(void **param_1,int *param_2,char *param_3)

{
  uint uVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  undefined *ptr;
  uint uVar5;
  uint uVar6;
  int num;
  uint uVar7;
  undefined *puVar8;
  undefined auStack_a0 [4];
  int local_9c;
  undefined4 local_98 [29];
  
  local_9c = 0;
  iVar4 = CONF_parse_list(param_3,0x3a,1,DAT_00070b70,&local_9c);
  iVar3 = local_9c;
  if ((iVar4 != 0) && (iVar4 = 1, param_1 != (void **)0x0)) {
    num = local_9c << 1;
    ptr = (undefined *)CRYPTO_malloc(num,DAT_00070b74,0x283);
    if (ptr == (undefined *)0x0) {
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
      if (*param_1 != (void *)0x0) {
        CRYPTO_free(*param_1);
      }
      iVar4 = 1;
      *param_1 = ptr;
      *param_2 = num;
    }
  }
  return iVar4;
}

