
long SSL_ctrl(SSL *ssl,int cmd,long larg,void *parg)

{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  long lVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  SSL_METHOD *pSVar8;
  
  if (0x73 < cmd - 0x10U) {
switchD_000e0f0a_caseD_11:
                    /* WARNING: Could not recover jumptable at 0x000e11ac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    lVar4 = (**(code **)(ssl->type + 0x44))(ssl);
    return lVar4;
  }
  iVar5 = larg >> 8;
  switch(cmd) {
  case 0x10:
    ssl->expand = (COMP_CTX *)parg;
    return 1;
  default:
    goto switchD_000e0f0a_caseD_11;
  case 0x21:
    uVar3 = ssl[3].new_session | larg;
    ssl[3].new_session = uVar3;
    return uVar3;
  case 0x28:
    return ssl[3].tlsext_hb_pending;
  case 0x29:
    uVar3 = ssl[3].tlsext_hb_pending;
    ssl[3].tlsext_hb_pending = larg;
    return uVar3;
  case 0x32:
    return ssl[3].state;
  case 0x33:
    if (larg < 0) {
      return 0;
    }
    iVar5 = ssl[3].state;
    ssl[3].state = larg;
    return iVar5;
  case 0x34:
    if (0x3e00 < larg - 0x200U) {
      return 0;
    }
    ssl[3].init_num = larg;
    if (ssl[3].init_msg <= (uint)larg) {
      return 1;
    }
    break;
  case 0x4c:
    if (ssl->mac_flags == 0) {
      return 0;
    }
    return *(long *)(ssl->mac_flags + 0x338);
  case 0x4e:
    uVar3 = ssl[3].new_session & ~larg;
    ssl[3].new_session = uVar3;
    return uVar3;
  case 99:
    uVar3 = *(uint *)(ssl[2].error + 0x10) | larg;
    *(uint *)(ssl[2].error + 0x10) = uVar3;
    return uVar3;
  case 100:
    uVar3 = *(uint *)(ssl[2].error + 0x10) & ~larg;
    *(uint *)(ssl[2].error + 0x10) = uVar3;
    return uVar3;
  case 0x6e:
    if (parg == (void *)0x0) {
      return 2;
    }
    iVar5 = *(int *)(ssl->mac_flags + 0x248);
    if (iVar5 == 0) {
      return 0;
    }
    *(int *)parg = iVar5;
    return *(long *)(ssl->mac_flags + 0x24c);
  case 0x7a:
    if (((ssl[2].tlsext_ticket_expected != 0) && (iVar5 = SSL_in_init(ssl), iVar5 == 0)) &&
       (iVar5 = ossl_statem_get_in_handshake(ssl), iVar5 == 0)) {
      return *(uint *)(ssl[2].tlsext_ticket_expected + 0x1fc) & 1;
    }
    return -1;
  case 0x7b:
    iVar7 = ssl[3].shutdown;
    if (larg == 0x100) {
      if ((iVar7 != 0x100) && (iVar7 >> 8 != 0xfe)) {
        bVar1 = true;
        goto LAB_000e1160;
      }
    }
    else {
      bVar1 = iVar5 == 0xfe;
      if ((iVar7 == 0x100) || (iVar7 >> 8 == 0xfe)) {
        if (iVar5 != 0xfe && larg != 0) {
          return 0;
        }
      }
      else {
LAB_000e1160:
        bVar2 = bVar1;
        if (iVar7 == 0) {
          bVar2 = false;
        }
        if (bVar2) {
          return 0;
        }
        if ((!bVar1) && (larg != 0)) {
          if (iVar7 == 0) {
            if (larg < 0x300) {
              return 0;
            }
          }
          else if (larg < 0x300 && 0x2ff < iVar7) {
            return 0;
          }
        }
      }
    }
    pSVar8 = ssl[3].method;
    piVar6 = &ssl[3].quiet_shutdown;
LAB_000e11cc:
    iVar5 = ssl_set_version_bound(*(undefined4 *)pSVar8->version,larg,piVar6);
    if (iVar5 != 0) {
      iVar5 = 1;
    }
    return iVar5;
  case 0x7c:
    iVar7 = ssl[3].quiet_shutdown;
    if (iVar7 == 0x100) {
      if ((larg != 0x100) && (iVar5 != 0xfe)) {
        bVar1 = true;
        goto LAB_000e10b2;
      }
    }
    else {
      bVar1 = iVar7 >> 8 == 0xfe;
      if ((larg == 0x100) || (iVar5 == 0xfe)) {
        if (iVar7 >> 8 != 0xfe && iVar7 != 0) {
          return 0;
        }
      }
      else {
LAB_000e10b2:
        bVar2 = bVar1;
        if (larg == 0) {
          bVar2 = false;
        }
        if (bVar2) {
          return 0;
        }
        if ((!bVar1) && (iVar7 != 0)) {
          if (larg == 0) {
            if (iVar7 < 0x300) {
              return 0;
            }
          }
          else if (0x2ff < larg && iVar7 < 0x300) {
            return 0;
          }
        }
      }
    }
    pSVar8 = ssl[3].method;
    piVar6 = &ssl[3].shutdown;
    goto LAB_000e11cc;
  case 0x7d:
    if ((uint)ssl[3].init_num < (uint)larg || larg == 0) {
      return 0;
    }
    break;
  case 0x7e:
    if (0x1f < larg - 1U) {
      return 0;
    }
    ssl[3].init_off = larg;
    if (larg == 1) {
      return 1;
    }
    ssl[3].tlsext_hb_pending = 1;
    return 1;
  case 0x82:
    return ssl[3].quiet_shutdown;
  case 0x83:
    return ssl[3].shutdown;
  }
  ssl[3].init_msg = (void *)larg;
  return 1;
}

