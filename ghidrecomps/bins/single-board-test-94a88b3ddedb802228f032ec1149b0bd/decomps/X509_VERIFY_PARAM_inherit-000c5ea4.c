
int X509_VERIFY_PARAM_inherit(X509_VERIFY_PARAM *to,X509_VERIFY_PARAM *from)

{
  int iVar1;
  _STACK *p_Var2;
  ASN1_OBJECT *pAVar3;
  char *pcVar4;
  int iVar5;
  time_t tVar6;
  ulong uVar7;
  uint uVar8;
  ulong uVar9;
  char *pcVar10;
  char *pcVar11;
  int *piVar12;
  int *piVar13;
  char *siz;
  _STACK **pp_Var14;
  _STACK *p_Var15;
  _STACK **pp_Var16;
  char *pcVar17;
  uint uVar18;
  bool bVar19;
  bool bVar20;
  
  if (from == (X509_VERIFY_PARAM *)0x0) {
    return 1;
  }
  uVar7 = from->inh_flags;
  piVar12 = (int *)from[1].name;
  uVar9 = to->inh_flags | uVar7;
  bVar19 = (int)(uVar9 << 0x1b) < 0;
  if (bVar19) {
    uVar7 = 0;
  }
  if (bVar19) {
    to->inh_flags = uVar7;
  }
  if ((int)(uVar9 << 0x1c) < 0) {
    return 1;
  }
  uVar18 = uVar9 & 1;
  if ((int)(uVar9 << 0x1e) < 0) {
    bVar19 = true;
    iVar1 = from->purpose;
    iVar5 = from->trust;
    to->depth = from->depth;
    uVar8 = to->flags;
    to->purpose = iVar1;
    to->trust = iVar5;
LAB_000c5ee8:
    tVar6 = from->check_time;
    to->flags = uVar8 & 0xfffffffd;
    to->check_time = tVar6;
  }
  else if (from->purpose == 0) {
LAB_000c6096:
    iVar1 = from->trust;
    if (iVar1 != 0) {
      if (uVar18 == 0) goto LAB_000c60a0;
LAB_000c60a6:
      to->trust = iVar1;
    }
LAB_000c60a8:
    iVar1 = from->depth;
    if (iVar1 == -1) goto LAB_000c60ba;
    if (uVar18 == 0) {
LAB_000c60b4:
      if (to->depth != -1) goto LAB_000c60ba;
    }
    to->depth = iVar1;
    uVar8 = to->flags;
    if ((uVar8 & 2) == 0) {
      bVar19 = false;
      goto LAB_000c5ee8;
    }
    bVar19 = false;
  }
  else {
    if ((uVar18 != 0) || (to->purpose == 0)) {
      to->purpose = from->purpose;
      goto LAB_000c6096;
    }
    iVar1 = from->trust;
    if (iVar1 == 0) goto LAB_000c60a8;
LAB_000c60a0:
    if (to->trust == 0) goto LAB_000c60a6;
    iVar1 = from->depth;
    if (iVar1 != -1) goto LAB_000c60b4;
LAB_000c60ba:
    uVar8 = to->flags;
    if ((uVar8 & 2) == 0) {
      bVar19 = false;
      goto LAB_000c5ee8;
    }
    bVar19 = false;
  }
  bVar20 = (int)(uVar9 << 0x1d) < 0;
  p_Var15 = &from->policies->stack;
  if (bVar20) {
    uVar8 = 0;
    uVar9 = uVar8;
  }
  else {
    uVar8 = to->flags;
  }
  if (bVar20) {
    to->flags = uVar9;
  }
  to->flags = from->flags | uVar8;
  if (bVar19) {
LAB_000c5f1e:
    if (&to->policies->stack != (_STACK *)0x0) {
      sk_pop_free(&to->policies->stack,DAT_000c6184);
    }
    if (p_Var15 == (_STACK *)0x0) {
      to->policies = (stack_st_ASN1_OBJECT *)0x0;
    }
    else {
LAB_000c5f30:
      p_Var2 = sk_new_null();
      to->policies = (stack_st_ASN1_OBJECT *)p_Var2;
      if (p_Var2 == (_STACK *)0x0) {
        return 0;
      }
      iVar1 = 0;
      while( true ) {
        iVar5 = sk_num(p_Var15);
        if (iVar5 <= iVar1) break;
        pAVar3 = (ASN1_OBJECT *)sk_value(p_Var15,iVar1);
        pAVar3 = OBJ_dup(pAVar3);
        if (pAVar3 == (ASN1_OBJECT *)0x0) {
          return 0;
        }
        iVar5 = sk_push(&to->policies->stack,pAVar3);
        iVar1 = iVar1 + 1;
        if (iVar5 == 0) {
          ASN1_OBJECT_free(pAVar3);
          return 0;
        }
      }
      to->flags = to->flags | 0x80;
    }
    if (!bVar19) {
      piVar13 = (int *)from[1].name;
LAB_000c6154:
      if (*piVar13 == 0) goto LAB_000c5fc6;
      if (uVar18 != 0) goto LAB_000c5f80;
LAB_000c60e4:
      pp_Var16 = (_STACK **)to[1].name;
      pp_Var14 = pp_Var16;
      if (*pp_Var16 == (_STACK *)0x0) goto LAB_000c5f96;
      if (piVar13[3] == 0) goto LAB_000c606a;
      goto LAB_000c6112;
    }
LAB_000c5f80:
    p_Var15 = *(_STACK **)to[1].name;
    pp_Var14 = (_STACK **)to[1].name;
    if (p_Var15 != (_STACK *)0x0) {
      sk_pop_free(p_Var15,DAT_000c6188);
      pp_Var14 = (_STACK **)to[1].name;
      *pp_Var14 = (_STACK *)0x0;
    }
LAB_000c5f96:
    pp_Var16 = pp_Var14;
    if (*piVar12 != 0) {
      p_Var15 = (_STACK *)sk_deep_copy(*piVar12,DAT_000c618c,DAT_000c6188);
      pp_Var16 = (_STACK **)to[1].name;
      *pp_Var14 = p_Var15;
      if (*pp_Var16 == (_STACK *)0x0) {
        return 0;
      }
      pp_Var16[1] = (_STACK *)piVar12[1];
    }
    if (bVar19) goto LAB_000c5fd8;
    piVar13 = (int *)from[1].name;
LAB_000c5fc6:
    if (piVar13[3] != 0) {
      if (uVar18 == 0) goto LAB_000c6110;
      pp_Var16 = (_STACK **)to[1].name;
      goto LAB_000c5fd8;
    }
LAB_000c606a:
    if (piVar13[5] == 0) {
      return 1;
    }
    if (uVar18 == 0) {
      pp_Var16 = (_STACK **)to[1].name;
LAB_000c6076:
      if (pp_Var16[5] != (_STACK *)0x0) {
        return 1;
      }
    }
  }
  else {
    piVar13 = piVar12;
    if (p_Var15 == (_STACK *)0x0) goto LAB_000c6154;
    if (uVar18 != 0) goto LAB_000c5f1e;
    if (to->policies == (stack_st_ASN1_OBJECT *)0x0) goto LAB_000c5f30;
    if (*piVar12 != 0) goto LAB_000c60e4;
    if (piVar12[3] == 0) goto LAB_000c606a;
LAB_000c6110:
    pp_Var16 = (_STACK **)to[1].name;
LAB_000c6112:
    if (pp_Var16[3] != (_STACK *)0x0) {
      if (piVar13[5] == 0) {
        return 1;
      }
      goto LAB_000c6076;
    }
LAB_000c5fd8:
    pcVar10 = (char *)piVar12[3];
    p_Var15 = (_STACK *)piVar12[4];
    if (pcVar10 == (char *)0x0) {
      p_Var15 = (_STACK *)0x0;
      p_Var2 = (_STACK *)0x0;
    }
    else {
      if (p_Var15 == (_STACK *)0x0) {
        p_Var2 = (_STACK *)BUF_strdup(pcVar10);
        p_Var15 = (_STACK *)strlen(pcVar10);
      }
      else {
        p_Var2 = (_STACK *)BUF_memdup(pcVar10,(size_t)p_Var15);
      }
      if (p_Var2 == (_STACK *)0x0) {
        return 0;
      }
    }
    if (pp_Var16[3] != (_STACK *)0x0) {
      CRYPTO_free(pp_Var16[3]);
    }
    pp_Var16[3] = p_Var2;
    if (pp_Var16 != (_STACK **)0xfffffff0) {
      pp_Var16[4] = p_Var15;
    }
    if (!bVar19) {
      piVar13 = (int *)from[1].name;
      goto LAB_000c606a;
    }
  }
  siz = (char *)piVar12[6];
  pcVar10 = (char *)piVar12[5];
  pcVar4 = pcVar10;
  if (((uint)siz & 0xfffffffb) == 0) {
    pcVar11 = to[1].name;
    pcVar17 = pcVar11 + 0x18;
    if (pcVar10 == (char *)0x0) goto LAB_000c6052;
    if (siz != (char *)0x0) goto LAB_000c6044;
    pcVar4 = BUF_strdup(pcVar10);
    siz = (char *)strlen(pcVar10);
  }
  else {
    if (siz != (char *)0x10) {
      return 0;
    }
    pcVar11 = to[1].name;
    pcVar17 = pcVar11 + 0x18;
    if (pcVar10 == (char *)0x0) goto LAB_000c6052;
LAB_000c6044:
    pcVar4 = (char *)BUF_memdup(pcVar10,(size_t)siz);
  }
  pcVar10 = siz;
  if (pcVar4 == (char *)0x0) {
    return 0;
  }
LAB_000c6052:
  if (*(void **)(pcVar11 + 0x14) != (void *)0x0) {
    CRYPTO_free(*(void **)(pcVar11 + 0x14));
  }
  *(char **)(pcVar11 + 0x14) = pcVar4;
  if (pcVar17 == (char *)0x0) {
    return 1;
  }
  *(char **)(pcVar11 + 0x18) = pcVar10;
  return 1;
}

