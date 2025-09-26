
int ossl_statem_client_write_transition(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  bool bVar5;
  
  uVar4 = *(uint *)((*(int **)(param_1 + 4))[0x19] + 0x30) & 8;
  if (uVar4 == 0) {
    iVar2 = **(int **)(param_1 + 4);
    iVar1 = iVar2 + -0x10000;
    if (iVar1 != 0) {
      iVar1 = 1;
    }
    if (iVar2 < 0x304) {
      iVar1 = 0;
    }
    if (iVar1 != 0) {
      switch(*(undefined4 *)(param_1 + 0x40)) {
      case 1:
        if (*(int *)(param_1 + 0x5f0) == -1) {
          return 2;
        }
        *(undefined4 *)(param_1 + 0x40) = 0x2b;
        return 1;
      default:
        ossl_statem_fatal(param_1,0x50,0x256,0x44,"ssl/statem/statem_clnt.c",0x1a2);
        return 0;
      case 7:
        if (*(int *)(param_1 + 0x5f4) != 4) {
          if ((*(uint *)(param_1 + 0x28) & 1) == 0) {
            ossl_statem_fatal(param_1,0x50,0x256,0x44,"ssl/statem/statem_clnt.c",0x1b2);
            return 0;
          }
          goto switchD_000f8f48_caseD_9;
        }
        goto LAB_000f908a;
      case 9:
      case 0x12:
      case 0x2b:
      case 0x2d:
        goto switchD_000f8f48_caseD_9;
      case 0xb:
        if ((*(uint *)(param_1 + 0x68) & 0xfffffffb) == 3) {
          *(undefined4 *)(param_1 + 0x40) = 0x2f;
          return 1;
        }
        if ((-1 < *(int *)(param_1 + 0x4ec) << 0xb) || (*(int *)(param_1 + 0x44c) != 0))
        goto switchD_000f8f48_caseD_10;
        break;
      case 0xd:
        if (*(int *)(*(int *)(param_1 + 0x7c) + 0x218) == 1) {
          uVar3 = 0xf;
        }
        else {
          uVar3 = 0x12;
        }
        *(undefined4 *)(param_1 + 0x40) = uVar3;
        return 1;
      case 0xf:
        goto switchD_000f8f0a_caseD_11;
      case 0x2f:
        iVar1 = *(int *)(param_1 + 0x5ac);
        bVar5 = iVar1 == 2;
        iVar2 = param_1;
        if (bVar5) {
          iVar1 = 0x30;
          iVar2 = 1;
        }
        if (bVar5) {
          *(int *)(param_1 + 0x40) = iVar1;
          return iVar2;
        }
      case 0x10:
      case 0x30:
switchD_000f8f48_caseD_10:
        if (*(int *)(*(int *)(param_1 + 0x7c) + 0x218) == 0) {
          uVar3 = 0x12;
        }
        else {
          uVar3 = 0xd;
        }
        *(undefined4 *)(param_1 + 0x40) = uVar3;
        return 1;
      }
      goto switchD_000f8f0a_caseD_f;
    }
  }
  switch(*(undefined4 *)(param_1 + 0x40)) {
  case 0:
  case 2:
    break;
  case 1:
    if (*(int *)(param_1 + 0x5ec) == 0) {
      return 2;
    }
    break;
  case 3:
    if ((*(int *)(param_1 + 0x4ec) << 0xb < 0) && (*(int *)(param_1 + 0x68) != 7))
    goto switchD_000f8f0a_caseD_f;
    break;
  default:
    ossl_statem_fatal(param_1,0x50,599,0x44,"ssl/statem/statem_clnt.c",0x202);
    return 0;
  case 8:
    if (*(int *)(*(int *)(param_1 + 0x7c) + 0x218) != 0) {
LAB_000f908a:
      *(undefined4 *)(param_1 + 0x40) = 0xd;
      return 1;
    }
  case 0xd:
    *(undefined4 *)(param_1 + 0x40) = 0xe;
    return 1;
  case 0xb:
    if (*(int *)(param_1 + 0x8c) == 0) goto switchD_000f8f48_caseD_9;
  case 0xf:
switchD_000f8f0a_caseD_f:
    *(undefined4 *)(param_1 + 0x40) = 0x10;
    return 1;
  case 0xc:
    if (*(int *)(param_1 + 0x68) != 2) {
      return 2;
    }
    if (-1 < *(int *)(param_1 + 0x4ec) << 0xb) {
LAB_000f912e:
      *(undefined4 *)(param_1 + 0x40) = 0x2e;
      return 1;
    }
    goto switchD_000f8f0a_caseD_f;
  case 0xe:
    iVar1 = **(int **)(param_1 + 0x7c);
    if ((*(int **)(param_1 + 0x7c))[0x86] == 1) {
      uVar3 = 0xf;
    }
    else {
      uVar3 = 0x10;
    }
    *(undefined4 *)(param_1 + 0x40) = uVar3;
    if (-1 < iVar1 << 0x1b) {
      return 1;
    }
    goto switchD_000f8f0a_caseD_f;
  case 0x10:
    if (*(int *)(param_1 + 0x44c) != 1) {
      if (*(int *)(param_1 + 0x68) == 2) goto LAB_000f912e;
      if ((uVar4 == 0) && (*(int *)(*(int *)(param_1 + 0x7c) + 0x33c) != 0)) {
        *(undefined4 *)(param_1 + 0x40) = 0x11;
        return 1;
      }
      goto switchD_000f8f0a_caseD_11;
    }
    break;
  case 0x11:
switchD_000f8f0a_caseD_11:
    *(undefined4 *)(param_1 + 0x40) = 0x12;
    return 1;
  case 0x12:
    if (*(int *)(param_1 + 0x8c) == 0) {
      return 2;
    }
switchD_000f8f48_caseD_9:
    *(undefined4 *)(param_1 + 0x40) = 1;
    return 1;
  case 0x29:
    iVar1 = ssl3_renegotiate_check(param_1,1);
    if (iVar1 == 0) goto switchD_000f8f48_caseD_9;
    iVar1 = tls_setup_handshake(param_1);
    if (iVar1 == 0) {
      return 0;
    }
    break;
  case 0x2e:
    return 2;
  }
  *(undefined4 *)(param_1 + 0x40) = 0xc;
  return 1;
}

