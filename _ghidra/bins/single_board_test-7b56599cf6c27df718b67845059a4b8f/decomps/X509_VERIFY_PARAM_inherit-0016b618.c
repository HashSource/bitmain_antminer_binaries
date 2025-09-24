
int X509_VERIFY_PARAM_inherit(X509_VERIFY_PARAM *to,X509_VERIFY_PARAM *from)

{
  int iVar1;
  time_t tVar2;
  ulong uVar3;
  stack_st_ASN1_OBJECT *psVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  bool bVar9;
  
  if (from == (X509_VERIFY_PARAM *)0x0) {
    return 1;
  }
  uVar3 = to->inh_flags;
  uVar6 = from->inh_flags | uVar3;
  bVar9 = (int)(uVar6 << 0x1b) < 0;
  if (bVar9) {
    uVar3 = 0;
  }
  if (bVar9) {
    to->inh_flags = uVar3;
  }
  if ((int)(uVar6 << 0x1c) < 0) {
    return 1;
  }
  uVar7 = uVar6 & 1;
  if ((int)(uVar6 << 0x1e) < 0) {
    iVar8 = from->purpose;
    bVar9 = true;
    iVar1 = from->trust;
    to->depth = from->depth;
    psVar4 = from->policies;
    to->purpose = iVar8;
    to->trust = iVar1;
    to->policies = psVar4;
    uVar5 = to->flags;
LAB_0016b652:
    tVar2 = from->check_time;
    uVar5 = uVar5 & 0xfffffffd;
    to->flags = uVar5;
    to->check_time = tVar2;
    if ((int)(uVar6 << 0x1d) < 0) {
LAB_0016b660:
      uVar5 = 0;
      to->flags = 0;
    }
    to->flags = uVar5 | from->flags;
    if (bVar9) {
      iVar1 = X509_VERIFY_PARAM_set1_policies(to,(stack_st_ASN1_OBJECT *)from[1].name);
      if (iVar1 == 0) {
        return 0;
      }
      to[1].inh_flags = from[1].inh_flags;
      OPENSSL_sk_pop_free(to[1].check_time,0x16b129);
      to[1].check_time = 0;
      if (from[1].check_time != 0) {
        iVar1 = OPENSSL_sk_deep_copy(from[1].check_time,0x16b199,0x16b129);
        to[1].check_time = iVar1;
        if (iVar1 == 0) {
          return 0;
        }
      }
      iVar1 = X509_VERIFY_PARAM_set1_email(to,from[1].purpose,from[1].trust);
      if (iVar1 == 0) {
        return 0;
      }
      iVar1 = from[1].depth;
      goto LAB_0016b750;
    }
  }
  else {
    if (from->purpose == 0) {
LAB_0016b6c0:
      iVar1 = from->trust;
      if (iVar1 != 0) {
        if (uVar7 == 0) goto LAB_0016b7c4;
LAB_0016b6c8:
        to->trust = iVar1;
      }
LAB_0016b6ca:
      iVar1 = from->depth;
      if (iVar1 == -1) goto LAB_0016b6d6;
      if (uVar7 != 0) {
LAB_0016b6d4:
        to->depth = iVar1;
        goto LAB_0016b6d6;
      }
LAB_0016b7d2:
      if (to->depth == -1) goto LAB_0016b6d4;
      psVar4 = from->policies;
      if (psVar4 != (stack_st_ASN1_OBJECT *)0xffffffff) goto LAB_0016b7e0;
    }
    else {
      if ((uVar7 != 0) || (to->purpose == 0)) {
        to->purpose = from->purpose;
        goto LAB_0016b6c0;
      }
      iVar1 = from->trust;
      if (iVar1 == 0) goto LAB_0016b6ca;
LAB_0016b7c4:
      if (to->trust == 0) goto LAB_0016b6c8;
      iVar1 = from->depth;
      if (iVar1 != -1) goto LAB_0016b7d2;
LAB_0016b6d6:
      psVar4 = from->policies;
      if (psVar4 != (stack_st_ASN1_OBJECT *)0xffffffff) {
        if (uVar7 == 0) {
LAB_0016b7e0:
          if (to->policies != (stack_st_ASN1_OBJECT *)0xffffffff) goto LAB_0016b6e2;
        }
        to->policies = psVar4;
      }
    }
LAB_0016b6e2:
    uVar5 = to->flags;
    if ((uVar5 & 2) == 0) {
      bVar9 = false;
      goto LAB_0016b652;
    }
    if ((int)(uVar6 << 0x1d) < 0) {
      bVar9 = false;
      goto LAB_0016b660;
    }
    to->flags = uVar5 | from->flags;
  }
  if ((stack_st_ASN1_OBJECT *)from[1].name == (stack_st_ASN1_OBJECT *)0x0) {
LAB_0016b760:
    uVar3 = from[1].inh_flags;
    if (uVar3 != 0) {
      if (uVar7 == 0) goto LAB_0016b7ea;
LAB_0016b768:
      to[1].inh_flags = uVar3;
    }
    if (from[1].check_time != 0) {
      if (uVar7 == 0) goto LAB_0016b690;
      tVar2 = to[1].check_time;
LAB_0016b774:
      OPENSSL_sk_pop_free(tVar2,0x16b129);
      to[1].check_time = 0;
      if (from[1].check_time != 0) {
        iVar1 = OPENSSL_sk_deep_copy(from[1].check_time,0x16b199,0x16b129);
        to[1].check_time = iVar1;
        if (iVar1 == 0) {
          return 0;
        }
      }
    }
LAB_0016b796:
    iVar1 = from[1].purpose;
    if (iVar1 == 0) goto LAB_0016b7ac;
    if (uVar7 != 0) {
LAB_0016b7a0:
      iVar1 = X509_VERIFY_PARAM_set1_email(to,iVar1,from[1].trust);
      if (iVar1 == 0) {
        return 0;
      }
      goto LAB_0016b7ac;
    }
LAB_0016b69e:
    if (to[1].purpose == 0) goto LAB_0016b7a0;
    iVar1 = from[1].depth;
    if (iVar1 == 0) {
      return 1;
    }
  }
  else {
    if ((uVar7 != 0) || (to[1].name == (char *)0x0)) {
      iVar1 = X509_VERIFY_PARAM_set1_policies(to,(stack_st_ASN1_OBJECT *)from[1].name);
      if (iVar1 == 0) {
        return 0;
      }
      goto LAB_0016b760;
    }
    uVar3 = from[1].inh_flags;
    if (uVar3 != 0) {
LAB_0016b7ea:
      if (to[1].inh_flags == 0) goto LAB_0016b768;
    }
    if (from[1].check_time == 0) goto LAB_0016b796;
LAB_0016b690:
    tVar2 = to[1].check_time;
    if (tVar2 == 0) goto LAB_0016b774;
    iVar1 = from[1].purpose;
    if (iVar1 != 0) goto LAB_0016b69e;
LAB_0016b7ac:
    iVar1 = from[1].depth;
    if (iVar1 == 0) {
      return 1;
    }
    if (uVar7 != 0) goto LAB_0016b750;
  }
  if (to[1].depth != 0) {
    return 1;
  }
LAB_0016b750:
  iVar1 = X509_VERIFY_PARAM_set1_ip(to,iVar1,from[1].policies);
  if (iVar1 != 0) {
    iVar1 = 1;
  }
  return iVar1;
}

