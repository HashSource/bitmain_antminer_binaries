
undefined4 ssl_get_prev_session(int *param_1,int param_2)

{
  bool bVar1;
  bool bVar2;
  SSL_SESSION *pSVar3;
  time_t tVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  int *piVar9;
  size_t __n;
  SSL_SESSION *local_1c;
  
  local_1c = (SSL_SESSION *)0x0;
  if ((*(uint *)(((int *)param_1[1])[0x19] + 0x30) & 8) == 0) {
    iVar6 = *(int *)param_1[1];
    iVar5 = iVar6 + -0x10000;
    if (iVar5 != 0) {
      iVar5 = 1;
    }
    if (iVar6 < 0x304) {
      iVar5 = 0;
    }
    if (iVar5 == 0) goto LAB_000e1b5a;
    uVar7 = *(undefined4 *)(param_2 + 0x268);
    param_1[0x157] = 1;
    iVar5 = tls_parse_extension(param_1,0x12,0x80,uVar7,0,0);
    if (iVar5 == 0) {
      return 0xffffffff;
    }
    iVar5 = tls_parse_extension(param_1,0x19,0x80,*(undefined4 *)(param_2 + 0x268),0,0);
    if (iVar5 == 0) {
      return 0xffffffff;
    }
    bVar1 = false;
    pSVar3 = (SSL_SESSION *)param_1[0x11d];
    goto joined_r0x000e1b4c;
  }
LAB_000e1b5a:
  uVar7 = tls_get_ticket_from_client(param_1,param_2,&local_1c);
  pSVar3 = local_1c;
  switch(uVar7) {
  case 0:
  case 1:
    bVar1 = false;
    ossl_statem_fatal(param_1,0x50,0xd9,0x44,"ssl/ssl_sess.c",0x213);
    goto LAB_000e1ba2;
  case 2:
  case 3:
    if (*(int *)(param_2 + 0x28) == 0) {
      bVar1 = false;
    }
    else {
      pSVar3 = (SSL_SESSION *)lookup_sess_in_cache(param_1,param_2 + 0x2c);
      bVar1 = true;
    }
    break;
  default:
    bVar1 = false;
  }
joined_r0x000e1b4c:
  if (pSVar3 == (SSL_SESSION *)0x0) {
    return 0;
  }
  local_1c = pSVar3;
  if (((pSVar3->ssl_version != *param_1) ||
      (__n = *(size_t *)(pSVar3->krb5_client_princ + 0xdc), __n != param_1[0x114])) ||
     (iVar5 = memcmp(pSVar3->krb5_client_princ + 0xe0,param_1 + 0x115,__n), iVar5 != 0)) {
    uVar7 = 0;
    goto LAB_000e1bac;
  }
  if (__n == 0) {
    uVar8 = param_1[299] & 1;
  }
  else {
    uVar8 = 0;
  }
  if (uVar8 == 0) {
    iVar5 = pSVar3->timeout;
    tVar4 = time((time_t *)0x0);
    uVar7 = 0;
    pSVar3 = local_1c;
    if (iVar5 < tVar4 - local_1c->time) {
      piVar9 = (int *)(param_1[0x178] + 0x54);
      do {
        ExclusiveAccess(piVar9);
        bVar2 = (bool)hasExclusiveAccess(piVar9);
      } while (!bVar2);
      *piVar9 = *piVar9 + 1;
      if (bVar1) {
        bVar1 = true;
        SSL_CTX_remove_session((SSL_CTX *)param_1[0x178],local_1c);
        pSVar3 = local_1c;
      }
      local_1c = pSVar3;
      if (pSVar3 == (SSL_SESSION *)0x0) {
        return 0;
      }
      goto LAB_000e1bac;
    }
    if ((*(uint *)local_1c[1].key_arg & 1) == 0) {
      if (-1 < *(int *)param_1[0x1f] << 0x16) goto LAB_000e1c5a;
      goto LAB_000e1bac;
    }
    if (*(int *)param_1[0x1f] << 0x16 < 0) {
LAB_000e1c5a:
      if ((*(int *)(((int *)param_1[1])[0x19] + 0x30) << 0x1c < 0) ||
         (iVar5 = *(int *)param_1[1], iVar5 < 0x304 || iVar5 == 0x10000)) {
        SSL_SESSION_free((SSL_SESSION *)param_1[0x11d]);
        param_1[0x11d] = (int)local_1c;
      }
      piVar9 = (int *)(param_1[0x178] + 0x5c);
      do {
        ExclusiveAccess(piVar9);
        bVar1 = (bool)hasExclusiveAccess(piVar9);
      } while (!bVar1);
      *piVar9 = *piVar9 + 1;
      param_1[0x136] = *(int *)(param_1[0x11d] + 0x1a4);
      return 1;
    }
    ossl_statem_fatal(param_1,0x2f,0xd9,0x68,"ssl/ssl_sess.c",0x255);
  }
  else {
    ossl_statem_fatal(param_1,0x50,0xd9,0x115,"ssl/ssl_sess.c",0x242);
  }
LAB_000e1ba2:
  uVar7 = 0xffffffff;
  pSVar3 = local_1c;
  if (local_1c == (SSL_SESSION *)0x0) {
    return 0xffffffff;
  }
LAB_000e1bac:
  SSL_SESSION_free(pSVar3);
  if (((*(uint *)(((int *)param_1[1])[0x19] + 0x30) & 8) == 0) &&
     (iVar5 = *(int *)param_1[1], iVar5 != 0x10000 && 0x303 < iVar5)) {
    param_1[0x11d] = 0;
  }
  if (!bVar1) {
    param_1[0x157] = 1;
  }
  return uVar7;
}

