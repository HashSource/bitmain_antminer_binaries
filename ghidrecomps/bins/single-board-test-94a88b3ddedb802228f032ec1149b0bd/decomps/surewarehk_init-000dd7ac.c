
undefined4 surewarehk_init(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  DSO *dso;
  DSO_FUNC_TYPE pDVar4;
  DSO_FUNC_TYPE pDVar5;
  DSO_FUNC_TYPE pDVar6;
  DSO_FUNC_TYPE pDVar7;
  DSO_FUNC_TYPE pDVar8;
  DSO_FUNC_TYPE pDVar9;
  DSO_FUNC_TYPE pDVar10;
  DSO_FUNC_TYPE pDVar11;
  DSO_FUNC_TYPE pDVar12;
  DSO_FUNC_TYPE pDVar13;
  DSO_FUNC_TYPE pDVar14;
  DSO_FUNC_TYPE pDVar15;
  DSO_FUNC_TYPE pDVar16;
  int iVar17;
  undefined4 local_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  iVar1 = DAT_000dda04;
  local_68 = *DAT_000dda00;
  uStack_64 = DAT_000dda00[1];
  uStack_60 = DAT_000dda00[2];
  local_5c = 0;
  local_58 = 0;
  local_54 = 0;
  local_50 = 0;
  local_4c = 0;
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  if (*(int *)(DAT_000dda04 + 0x24) == 0) {
    dso = DSO_load((DSO *)0x0,DAT_000dda0c,(DSO_METHOD *)0x0,0);
    *(DSO **)(iVar1 + 0x24) = dso;
    if (dso == (DSO *)0x0) {
      iVar3 = *(int *)(iVar1 + 4);
      if (iVar3 == 0) {
        iVar3 = ERR_get_next_error_library();
        *(int *)(iVar1 + 4) = iVar3;
      }
      iVar17 = 0x1df;
    }
    else {
      pDVar4 = DSO_bind_func(dso,DAT_000dda10);
      if (((((pDVar4 != (DSO_FUNC_TYPE)0x0) &&
            (pDVar5 = DSO_bind_func(*(DSO **)(iVar1 + 0x24),DAT_000dda14),
            pDVar5 != (DSO_FUNC_TYPE)0x0)) &&
           (pDVar6 = DSO_bind_func(*(DSO **)(iVar1 + 0x24),DAT_000dda18),
           pDVar6 != (DSO_FUNC_TYPE)0x0)) &&
          (((pDVar7 = DSO_bind_func(*(DSO **)(iVar1 + 0x24),DAT_000dda1c),
            pDVar7 != (DSO_FUNC_TYPE)0x0 &&
            (pDVar8 = DSO_bind_func(*(DSO **)(iVar1 + 0x24),DAT_000dda20),
            pDVar8 != (DSO_FUNC_TYPE)0x0)) &&
           ((pDVar9 = DSO_bind_func(*(DSO **)(iVar1 + 0x24),DAT_000dda24),
            pDVar9 != (DSO_FUNC_TYPE)0x0 &&
            ((pDVar10 = DSO_bind_func(*(DSO **)(iVar1 + 0x24),DAT_000dda28),
             pDVar10 != (DSO_FUNC_TYPE)0x0 &&
             (pDVar11 = DSO_bind_func(*(DSO **)(iVar1 + 0x24),DAT_000dda2c),
             pDVar11 != (DSO_FUNC_TYPE)0x0)))))))) &&
         ((pDVar12 = DSO_bind_func(*(DSO **)(iVar1 + 0x24),DAT_000dda30), iVar3 = DAT_000dda04,
          pDVar12 != (DSO_FUNC_TYPE)0x0 &&
          ((((pDVar13 = DSO_bind_func(*(DSO **)(DAT_000dda04 + 0x24),DAT_000dda34),
             pDVar13 != (DSO_FUNC_TYPE)0x0 &&
             (pDVar14 = DSO_bind_func(*(DSO **)(iVar3 + 0x24),DAT_000dda38),
             pDVar14 != (DSO_FUNC_TYPE)0x0)) &&
            (pDVar15 = DSO_bind_func(*(DSO **)(iVar3 + 0x24),DAT_000dda3c),
            pDVar15 != (DSO_FUNC_TYPE)0x0)) &&
           (pDVar16 = DSO_bind_func(*(DSO **)(iVar3 + 0x24),DAT_000dda40),
           pDVar16 != (DSO_FUNC_TYPE)0x0)))))) {
        *(DSO_FUNC_TYPE *)(iVar3 + 0x2c) = pDVar5;
        *(DSO_FUNC_TYPE *)(iVar3 + 0x28) = pDVar4;
        uVar2 = threadsafe;
        *(DSO_FUNC_TYPE *)(iVar3 + 0x30) = pDVar6;
        *(DSO_FUNC_TYPE *)(iVar3 + 0xc) = pDVar7;
        *(DSO_FUNC_TYPE *)(iVar3 + 0x14) = pDVar9;
        *(DSO_FUNC_TYPE *)(iVar3 + 0x20) = pDVar8;
        *(DSO_FUNC_TYPE *)(iVar3 + 0x18) = pDVar15;
        *(DSO_FUNC_TYPE *)(iVar3 + 8) = pDVar10;
        *(DSO_FUNC_TYPE *)(iVar3 + 0x10) = pDVar16;
        *(DSO_FUNC_TYPE *)(iVar3 + 0x34) = pDVar11;
        *(DSO_FUNC_TYPE *)(iVar3 + 0x38) = pDVar12;
        *(DSO_FUNC_TYPE *)(iVar3 + 0x3c) = pDVar13;
        *(DSO_FUNC_TYPE *)(iVar3 + 0x1c) = pDVar14;
        iVar17 = (*pDVar4)(&local_68,uVar2);
        if (iVar17 == -3) {
          ERR_SUREWARE_error_constprop_5(0x68,0x68,0x21c);
        }
        else {
          iVar3 = (**(code **)(iVar3 + 0x28))(&local_68,threadsafe);
          if (iVar3 != -3) {
            surewarehk_load_privkey(param_1,0,0,0);
            if (rsaHndidx == -1) {
              rsaHndidx = RSA_get_ex_new_index
                                    (0,DAT_000dda6c,(undefined1 *)0x0,(undefined1 *)0x0,DAT_000dda68
                                    );
            }
            iVar1 = DAT_000dda44;
            if (dsaHndidx != -1) {
              return 1;
            }
            iVar3 = DSA_get_ex_new_index
                              (0,DAT_000dda4c,(undefined1 *)0x0,(undefined1 *)0x0,DAT_000dda48);
            *(int *)(iVar1 + 0xd8) = iVar3;
            return 1;
          }
          ERR_SUREWARE_error_constprop_5(0x68,0x68,0x220);
        }
        goto LAB_000dd7fe;
      }
      iVar17 = DAT_000dda04;
      iVar3 = *(int *)(iVar1 + 4);
      if (iVar3 == 0) {
        iVar3 = ERR_get_next_error_library();
        *(int *)(iVar17 + 4) = iVar3;
      }
      iVar17 = 0x209;
    }
    ERR_put_error(iVar3,0x68,0x68,DAT_000dda08,iVar17);
  }
  else {
    iVar3 = *(int *)(DAT_000dda04 + 4);
    if (iVar3 == 0) {
      iVar3 = ERR_get_next_error_library();
      *(int *)(iVar1 + 4) = iVar3;
    }
    ERR_put_error(iVar3,0x68,100,DAT_000dda08,0x1d9);
  }
LAB_000dd7fe:
  if (*(DSO **)(iVar1 + 0x24) != (DSO *)0x0) {
    DSO_free(*(DSO **)(iVar1 + 0x24));
  }
  *(undefined4 *)(iVar1 + 0x24) = 0;
  *(undefined4 *)(iVar1 + 0x28) = 0;
  *(undefined4 *)(iVar1 + 0x2c) = 0;
  *(undefined4 *)(iVar1 + 0x30) = 0;
  *(undefined4 *)(iVar1 + 0xc) = 0;
  *(undefined4 *)(iVar1 + 0x20) = 0;
  *(undefined4 *)(iVar1 + 0x14) = 0;
  *(undefined4 *)(iVar1 + 8) = 0;
  *(undefined4 *)(iVar1 + 0x34) = 0;
  *(undefined4 *)(iVar1 + 0x38) = 0;
  *(undefined4 *)(iVar1 + 0x3c) = 0;
  *(undefined4 *)(iVar1 + 0x1c) = 0;
  *(undefined4 *)(iVar1 + 0x18) = 0;
  *(undefined4 *)(iVar1 + 0x10) = 0;
  return 0;
}

