
undefined4 parse_ca_names(int param_1,undefined4 *param_2)

{
  uchar *puVar1;
  int iVar2;
  X509_NAME *a;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  undefined1 *puVar8;
  uchar *puVar9;
  uchar *local_2c [2];
  
  iVar2 = OPENSSL_sk_new(0xfcd29);
  if (iVar2 == 0) {
    ossl_statem_fatal(param_1,0x50,0x21d,0x41,"ssl/statem/statem_lib.c",0x8d7);
    a = (X509_NAME *)0x0;
    goto LAB_000ff1c6;
  }
  if ((uint)param_2[1] < 2) {
LAB_000ff1e0:
    uVar6 = 0x8dd;
  }
  else {
    puVar8 = (undefined1 *)*param_2;
    uVar5 = param_2[1] - 2;
    uVar4 = (uint)CONCAT11(*puVar8,puVar8[1]);
    if (uVar5 < uVar4) goto LAB_000ff1e0;
    *param_2 = puVar8 + uVar4 + 2;
    param_2[1] = uVar5 - uVar4;
    if (uVar4 == 0) {
LAB_000ff208:
      OPENSSL_sk_pop_free(*(undefined4 *)(*(int *)(param_1 + 0x7c) + 0x224),(undefined *)0x177669);
      *(int *)(*(int *)(param_1 + 0x7c) + 0x224) = iVar2;
      return 1;
    }
    if (uVar4 != 1) {
      uVar4 = uVar4 - 2;
      uVar5 = (uint)CONCAT11(puVar8[2],puVar8[3]);
      if (uVar5 <= uVar4) {
        puVar9 = puVar8 + 4;
        do {
          iVar7 = uVar4 - uVar5;
          local_2c[0] = puVar9;
          a = d2i_X509_NAME((X509_NAME **)0x0,local_2c,uVar5);
          puVar1 = local_2c[0];
          if (a == (X509_NAME *)0x0) {
            ossl_statem_fatal(param_1,0x32,0x21d,0xd,"ssl/statem/statem_lib.c",0x8ef);
            goto LAB_000ff1c6;
          }
          if (local_2c[0] != puVar9 + uVar5) {
            ossl_statem_fatal(param_1,0x32,0x21d,0x83,"ssl/statem/statem_lib.c",0x8f4);
            goto LAB_000ff1c6;
          }
          iVar3 = OPENSSL_sk_push(iVar2,a);
          if (iVar3 == 0) {
            ossl_statem_fatal(param_1,0x50,0x21d,0x41,"ssl/statem/statem_lib.c",0x8fa);
            goto LAB_000ff1c6;
          }
          uVar4 = iVar7 - 2;
          puVar9 = puVar1 + 2;
          if (iVar7 == 0) goto LAB_000ff208;
        } while ((iVar7 != 1) && (uVar5 = (uint)CONCAT11(*puVar1,puVar1[1]), uVar5 <= uVar4));
      }
    }
    uVar6 = 0x8e8;
  }
  a = (X509_NAME *)0x0;
  ossl_statem_fatal(param_1,0x32,0x21d,0x9f,"ssl/statem/statem_lib.c",uVar6);
LAB_000ff1c6:
  OPENSSL_sk_pop_free(iVar2,(undefined *)0x177669);
  X509_NAME_free(a);
  return 0;
}

