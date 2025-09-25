
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
LAB_00167402:
    tVar2 = from->check_time;
    uVar5 = uVar5 & 0xfffffffd;
    to->flags = uVar5;
    to->check_time = tVar2;
    if ((int)(uVar6 << 0x1d) < 0) {
LAB_00167410:
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
      OPENSSL_sk_pop_free(to[1].check_time,0x166ed9);
      to[1].check_time = 0;
      if (from[1].check_time != 0) {
        iVar1 = OPENSSL_sk_deep_copy(from[1].check_time,0x166f49,0x166ed9);
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
      goto LAB_00167500;
    }
  }
  else {
    if (from->purpose == 0) {
LAB_00167470:
      iVar1 = from->trust;
      if (iVar1 != 0) {
        if (uVar7 == 0) goto LAB_00167574;
LAB_00167478:
        to->trust = iVar1;
      }
LAB_0016747a:
      iVar1 = from->depth;
      if (iVar1 == -1) goto LAB_00167486;
      if (uVar7 != 0) {
LAB_00167484:
        to->depth = iVar1;
        goto LAB_00167486;
      }
LAB_00167582:
      if (to->depth == -1) goto LAB_00167484;
      psVar4 = from->policies;
      if (psVar4 != (stack_st_ASN1_OBJECT *)0xffffffff) goto LAB_00167590;
    }
    else {
      if ((uVar7 != 0) || (to->purpose == 0)) {
        to->purpose = from->purpose;
        goto LAB_00167470;
      }
      iVar1 = from->trust;
      if (iVar1 == 0) goto LAB_0016747a;
LAB_00167574:
      if (to->trust == 0) goto LAB_00167478;
      iVar1 = from->depth;
      if (iVar1 != -1) goto LAB_00167582;
LAB_00167486:
      psVar4 = from->policies;
      if (psVar4 != (stack_st_ASN1_OBJECT *)0xffffffff) {
        if (uVar7 == 0) {
LAB_00167590:
          if (to->policies != (stack_st_ASN1_OBJECT *)0xffffffff) goto LAB_00167492;
        }
        to->policies = psVar4;
      }
    }
LAB_00167492:
    uVar5 = to->flags;
    if ((uVar5 & 2) == 0) {
      bVar9 = false;
      goto LAB_00167402;
    }
    if ((int)(uVar6 << 0x1d) < 0) {
      bVar9 = false;
      goto LAB_00167410;
    }
    to->flags = uVar5 | from->flags;
  }
  if ((stack_st_ASN1_OBJECT *)from[1].name == (stack_st_ASN1_OBJECT *)0x0) {
LAB_00167510:
    uVar3 = from[1].inh_flags;
    if (uVar3 != 0) {
      if (uVar7 == 0) goto LAB_0016759a;
LAB_00167518:
      to[1].inh_flags = uVar3;
    }
    if (from[1].check_time != 0) {
      if (uVar7 == 0) goto LAB_00167440;
      tVar2 = to[1].check_time;
LAB_00167524:
      OPENSSL_sk_pop_free(tVar2,0x166ed9);
      to[1].check_time = 0;
      if (from[1].check_time != 0) {
        iVar1 = OPENSSL_sk_deep_copy(from[1].check_time,0x166f49,0x166ed9);
        to[1].check_time = iVar1;
        if (iVar1 == 0) {
          return 0;
        }
      }
    }
LAB_00167546:
    iVar1 = from[1].purpose;
    if (iVar1 == 0) goto LAB_0016755c;
    if (uVar7 != 0) {
LAB_00167550:
      iVar1 = X509_VERIFY_PARAM_set1_email(to,iVar1,from[1].trust);
      if (iVar1 == 0) {
        return 0;
      }
      goto LAB_0016755c;
    }
LAB_0016744e:
    if (to[1].purpose == 0) goto LAB_00167550;
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
      goto LAB_00167510;
    }
    uVar3 = from[1].inh_flags;
    if (uVar3 != 0) {
LAB_0016759a:
      if (to[1].inh_flags == 0) goto LAB_00167518;
    }
    if (from[1].check_time == 0) goto LAB_00167546;
LAB_00167440:
    tVar2 = to[1].check_time;
    if (tVar2 == 0) goto LAB_00167524;
    iVar1 = from[1].purpose;
    if (iVar1 != 0) goto LAB_0016744e;
LAB_0016755c:
    iVar1 = from[1].depth;
    if (iVar1 == 0) {
      return 1;
    }
    if (uVar7 != 0) goto LAB_00167500;
  }
  if (to[1].depth != 0) {
    return 1;
  }
LAB_00167500:
  iVar1 = X509_VERIFY_PARAM_set1_ip(to,iVar1,from[1].policies);
  if (iVar1 != 0) {
    iVar1 = 1;
  }
  return iVar1;
}

