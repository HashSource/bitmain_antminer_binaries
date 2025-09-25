
undefined4
tls_collect_extensions
          (int param_1,undefined4 *param_2,uint param_3,undefined4 *param_4,int *param_5,int param_6
          )

{
  void *ptr;
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  uint uVar7;
  uint *puVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  undefined1 *puVar12;
  uint uVar13;
  uint uVar14;
  undefined1 *puVar15;
  code *pcVar16;
  int local_38;
  int local_2c [2];
  
  iVar10 = *(int *)(param_1 + 0x404);
  puVar12 = (undefined1 *)*param_2;
  uVar13 = param_2[1];
  iVar4 = iVar10 + 0xf0;
  *param_4 = 0;
  uVar7 = param_3 & 0x80;
  if (uVar7 != 0) {
    custom_ext_init(*(int *)(param_1 + 0x404) + 0xf0);
  }
  if (iVar4 == 0) {
    iVar10 = 0x270;
    local_38 = 0x1a;
  }
  else {
    local_38 = *(int *)(iVar10 + 0xf4) + 0x1a;
    iVar10 = local_38 * 0x18;
  }
  ptr = (void *)CRYPTO_zalloc(iVar10,"ssl/statem/extensions.c",0x241);
  if (ptr == (void *)0x0) {
    ossl_statem_fatal(param_1,0x50,0x1b3,0x41,"ssl/statem/extensions.c",0x244);
  }
  else {
    if (uVar13 == 0) {
LAB_000e30fe:
      if (param_6 != 0) {
        puVar6 = &ext_defs;
        do {
          while (((HintPreloadData(puVar6 + 0x29), puVar6[2] == 0 || ((param_3 & puVar6[1]) == 0))
                 || (iVar4 = extension_is_relevant(param_1,puVar6[1],param_3), iVar4 == 0))) {
            puVar6 = puVar6 + 8;
            if (puVar6 == &tls_version_table) goto LAB_000e3148;
          }
          iVar4 = (*(code *)puVar6[2])(param_1,param_3);
          if (iVar4 == 0) goto LAB_000e300e;
          puVar6 = puVar6 + 8;
        } while (puVar6 != &tls_version_table);
      }
LAB_000e3148:
      *param_4 = ptr;
      if (param_5 != (int *)0x0) {
        *param_5 = local_38;
      }
      return 1;
    }
    if (1 < uVar13) {
      iVar10 = 0;
      do {
        uVar11 = (uint)CONCAT11(*puVar12,puVar12[1]);
        if (uVar13 - 2 < 2) break;
        puVar15 = puVar12 + 4;
        uVar14 = (uint)CONCAT11(puVar12[2],puVar12[3]);
        if (uVar13 - 4 < uVar14) break;
        uVar13 = (uVar13 - 4) - uVar14;
        puVar12 = puVar15 + uVar14;
        iVar5 = 0;
        puVar8 = &ext_defs;
        do {
          if (uVar11 == *puVar8) {
            uVar9 = puVar8[1];
            if ((param_3 & uVar9) == 0) goto LAB_000e307e;
            if (*(int *)(*(int *)(*(int *)(param_1 + 4) + 100) + 0x30) << 0x1c < 0) {
              iVar1 = uVar9 << 0x1f;
            }
            else {
              iVar1 = uVar9 << 0x1e;
            }
            if (iVar1 < 0) goto LAB_000e307e;
            puVar6 = (undefined4 *)((int)ptr + iVar5 * 0x18);
            if (puVar6 != (undefined4 *)0x0) goto LAB_000e2f3c;
            goto LAB_000e3074;
          }
          iVar5 = iVar5 + 1;
          puVar8 = puVar8 + 8;
        } while (iVar5 != 0x1a);
        if (iVar4 != 0) {
          local_2c[0] = 0;
          if (uVar7 == 0) {
            if ((param_3 & 0x100) == 0) {
              uVar3 = 2;
            }
            else {
              uVar3 = 0;
            }
          }
          else {
            uVar3 = 1;
          }
          iVar5 = custom_ext_find(iVar4,uVar3,uVar11,local_2c);
          if (iVar5 == 0) goto LAB_000e3074;
          uVar9 = *(uint *)(iVar5 + 8);
          if ((param_3 & uVar9) != 0) {
            if (-1 < *(int *)(*(int *)(*(int *)(param_1 + 4) + 100) + 0x30) << 0x1c) {
              if (-1 < (int)(uVar9 << 0x1e)) goto LAB_000e3064;
              goto LAB_000e307e;
            }
            if ((int)(uVar9 << 0x1f) < 0) goto LAB_000e307e;
LAB_000e3064:
            puVar6 = (undefined4 *)((int)ptr + (local_2c[0] + 0x1a) * 0x18);
            if (puVar6 == (undefined4 *)0x0) goto LAB_000e3074;
LAB_000e2f3c:
            if (puVar6[2] == 1) goto LAB_000e307e;
            goto LAB_000e2f44;
          }
LAB_000e307e:
          ossl_statem_fatal(param_1,0x2f,0x1b3,0x6e,"ssl/statem/extensions.c",0x25f);
          goto LAB_000e300e;
        }
LAB_000e3074:
        puVar6 = (undefined4 *)0x0;
LAB_000e2f44:
        if ((uVar7 != 0 && uVar11 == 0x29) && (uVar13 != 0)) goto LAB_000e307e;
        uVar9 = ((int)puVar6 - (int)ptr >> 3) * -0x55555555;
        if (uVar9 < 0x1a) {
          uVar2 = uVar11 - 0x2c;
          if (uVar2 != 0) {
            uVar2 = 1;
          }
          if ((param_3 & 0x6080) != 0) {
            uVar2 = 0;
          }
          if (uVar11 == 0xff01) {
            uVar2 = 0;
          }
          else {
            uVar2 = uVar2 & 1;
          }
          if (uVar11 == 0x12) {
            uVar2 = 0;
          }
          if ((uVar2 != 0) && (-1 < (int)((uint)*(byte *)(uVar9 + param_1 + 0x514) << 0x1e))) {
            uVar9 = uVar11 - 65000;
            if (uVar9 != 0) {
              uVar9 = 1;
            }
            if ((param_3 & 0x100) == 0) {
              uVar9 = uVar9 | 1;
            }
            if (uVar9 != 0) {
              ossl_statem_fatal(param_1,0x6e,0x1b3,0xd9,"ssl/statem/extensions.c",0x27f);
              goto LAB_000e300e;
            }
          }
        }
        iVar5 = iVar10;
        if (puVar6 != (undefined4 *)0x0) {
          *puVar6 = puVar15;
          puVar6[1] = uVar14;
          iVar5 = iVar10 + 1;
          pcVar16 = *(code **)(param_1 + 0x530);
          puVar6[5] = iVar10;
          puVar6[4] = uVar11;
          puVar6[2] = 1;
          if (pcVar16 != (code *)0x0) {
            (*pcVar16)(param_1,*(int *)(param_1 + 0x1c) == 0,uVar11,puVar15,uVar14,
                       *(undefined4 *)(param_1 + 0x534));
          }
        }
        if (uVar13 == 0) goto LAB_000e30fe;
        iVar10 = iVar5;
      } while (uVar13 != 1);
    }
    ossl_statem_fatal(param_1,0x32,0x1b3,0x6e,"ssl/statem/extensions.c",0x251);
LAB_000e300e:
    CRYPTO_free(ptr);
  }
  return 0;
}

