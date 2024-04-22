
undefined4
ssl_cipher_get_evp(int *param_1,EVP_CIPHER **param_2,_STACK **param_3,int *param_4,_STACK **param_5,
                  void **param_6)

{
  _STACK **pp_Var1;
  _STACK *st;
  int iVar2;
  void *pvVar3;
  ulong uVar4;
  EVP_CIPHER *pEVar5;
  uint uVar6;
  int iVar7;
  int local_34 [4];
  
  pp_Var1 = DAT_00080264;
  iVar7 = param_1[0x2d];
  if (iVar7 == 0) {
    return 0;
  }
  if (param_6 != (void **)0x0) {
    load_builtin_compressions();
    local_34[0] = param_1[0x2c];
    st = *pp_Var1;
    *param_6 = (void *)0x0;
    if (st != (_STACK *)0x0) {
      iVar2 = sk_find(st,local_34);
      if (iVar2 < 0) {
        *param_6 = (void *)0x0;
      }
      else {
        pvVar3 = sk_value(*pp_Var1,iVar2);
        *param_6 = pvVar3;
      }
    }
  }
  if (param_2 == (EVP_CIPHER **)0x0 || param_3 == (_STACK **)0x0) {
    return 0;
  }
  iVar2 = 0;
  uVar6 = *(uint *)(iVar7 + 0x14);
  if (uVar6 == 0x40) {
    iVar2 = 6;
LAB_0008010a:
    *param_2 = (EVP_CIPHER *)DAT_00080264[iVar2 + 1];
  }
  else {
    if (0x40 < uVar6) {
      if (uVar6 == 0x400) {
        iVar2 = 10;
      }
      else if (uVar6 < 0x401) {
        if (uVar6 == 0x100) {
          iVar2 = 8;
        }
        else if (uVar6 == 0x200) {
          iVar2 = 9;
        }
        else {
          if (uVar6 != 0x80) goto LAB_000800f4;
          iVar2 = 7;
        }
      }
      else if (uVar6 == 0x1000) {
        iVar2 = 0xc;
      }
      else if (uVar6 == 0x2000) {
        iVar2 = 0xd;
      }
      else {
        if (uVar6 != 0x800) goto LAB_000800f4;
        iVar2 = 0xb;
      }
      goto LAB_0008010a;
    }
    if (uVar6 == 4) {
      iVar2 = 2;
      goto LAB_0008010a;
    }
    if (4 < uVar6) {
      if (uVar6 == 0x10) {
        iVar2 = 4;
      }
      else {
        if (uVar6 == 0x20) {
          pEVar5 = EVP_enc_null();
          *param_2 = pEVar5;
          goto LAB_00080114;
        }
        if (uVar6 != 8) goto LAB_000800f4;
        iVar2 = 3;
      }
      goto LAB_0008010a;
    }
    if (uVar6 == 1) goto LAB_0008010a;
    if (uVar6 == 2) {
      iVar2 = 1;
      goto LAB_0008010a;
    }
LAB_000800f4:
    *param_2 = (EVP_CIPHER *)0x0;
  }
LAB_00080114:
  pp_Var1 = DAT_00080264;
  iVar2 = *(int *)(iVar7 + 0x18);
  uVar6 = iVar2 - 1;
  if ((uVar6 < 0x20) && (uVar6 = (uint)*(char *)(DAT_00080268 + uVar6), uVar6 < 6)) {
    *param_3 = DAT_00080264[uVar6 + 0xf];
    if (param_4 != (int *)0x0) {
      *param_4 = *(int *)(DAT_0008026c + uVar6 * 4);
    }
    if (param_5 != (_STACK **)0x0) {
      *param_5 = pp_Var1[uVar6 + 0x15];
    }
  }
  else {
    *param_3 = (_STACK *)0x0;
    if (param_4 != (int *)0x0) {
      *param_4 = 0;
    }
    if (param_5 != (_STACK **)0x0) {
      *param_5 = (_STACK *)0x0;
    }
    if (iVar2 == 0x40) {
      param_4 = (int *)0x0;
    }
  }
  if (((*param_2 == (EVP_CIPHER *)0x0) ||
      ((*param_3 == (_STACK *)0x0 && (uVar4 = EVP_CIPHER_flags(*param_2), -1 < (int)(uVar4 << 10))))
      ) || ((param_4 != (int *)0x0 && (*param_4 == 0)))) {
    return 0;
  }
  if (*param_1 >> 8 != 3) {
    return 1;
  }
  if (*param_1 < 0x301) {
    return 1;
  }
  iVar2 = *(int *)(iVar7 + 0x14);
  if (iVar2 == 4) {
    if (*(int *)(iVar7 + 0x18) != 1) {
      return 1;
    }
    pEVar5 = EVP_get_cipherbyname(DAT_00080278);
    if (pEVar5 != (EVP_CIPHER *)0x0) goto LAB_000801c4;
    iVar2 = *(int *)(iVar7 + 0x14);
  }
  if (iVar2 == 0x40) {
    iVar2 = *(int *)(iVar7 + 0x18);
    if (iVar2 == 2) {
      pEVar5 = EVP_get_cipherbyname(DAT_00080280);
      if (pEVar5 != (EVP_CIPHER *)0x0) goto LAB_000801c4;
      iVar2 = *(int *)(iVar7 + 0x14);
      goto LAB_000801ac;
    }
LAB_000801fa:
    if (iVar2 != 0x10) {
      return 1;
    }
    pEVar5 = EVP_get_cipherbyname(DAT_00080274);
    if (pEVar5 != (EVP_CIPHER *)0x0) goto LAB_000801c4;
    iVar2 = *(int *)(iVar7 + 0x14);
LAB_0008020a:
    if (iVar2 != 0x80) {
      return 1;
    }
    iVar2 = *(int *)(iVar7 + 0x18);
  }
  else {
LAB_000801ac:
    if (iVar2 != 0x80) {
LAB_0008024e:
      if (iVar2 == 0x40) {
        iVar2 = *(int *)(iVar7 + 0x18);
        goto LAB_000801fa;
      }
      goto LAB_0008020a;
    }
    iVar2 = *(int *)(iVar7 + 0x18);
    if (iVar2 == 2) {
      pEVar5 = EVP_get_cipherbyname(DAT_0008027c);
      if (pEVar5 != (EVP_CIPHER *)0x0) goto LAB_000801c4;
      iVar2 = *(int *)(iVar7 + 0x14);
      goto LAB_0008024e;
    }
  }
  if ((iVar2 != 0x10) || (pEVar5 = EVP_get_cipherbyname(DAT_00080270), pEVar5 == (EVP_CIPHER *)0x0))
  {
    return 1;
  }
LAB_000801c4:
  *param_2 = pEVar5;
  *param_3 = (_STACK *)0x0;
  return 1;
}

