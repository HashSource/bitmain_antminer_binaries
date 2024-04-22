
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int RAND_poll(void)

{
  __uid_t _Var1;
  int iVar2;
  int iVar3;
  uint uVar4;
  char *path;
  ssize_t sVar5;
  int *piVar6;
  size_t len;
  char **ppcVar7;
  uint uVar8;
  int in_stack_fffffe98;
  __uid_t local_15c;
  pollfd local_158;
  uchar auStack_150 [32];
  undefined local_130 [12];
  int local_124 [64];
  
  ppcVar7 = DAT_00103a04;
  len = 0;
  uVar8 = 0;
  _Var1 = getpid();
  memset(local_130,0,0x108);
  do {
    ppcVar7 = ppcVar7 + 1;
    iVar2 = open(*ppcVar7,0x900);
    if (-1 < iVar2) {
      iVar3 = __fxstat(3,iVar2,(stat *)(local_130 + uVar8 * 0x58));
      if (iVar3 == 0) {
        if (uVar8 != 0) {
          piVar6 = local_124;
          uVar4 = 0;
          do {
            in_stack_fffffe98 = iVar2;
            if ((*piVar6 == local_124[uVar8 * 0x16]) &&
               (piVar6[-2] == *(int *)(local_130 + uVar8 * 0x58 + 4) &&
                piVar6[-3] == *(int *)&((stat *)(local_130 + uVar8 * 0x58))->st_dev)) {
              if (uVar4 < uVar8) goto LAB_0010390a;
              break;
            }
            uVar4 = uVar4 + 1;
            piVar6 = piVar6 + 0x16;
          } while (uVar4 != uVar8);
        }
        local_158.events = 1;
        local_158.revents = 0;
        local_158.fd = iVar2;
        iVar3 = poll(&local_158,1,10);
        if (((-1 < iVar3) && ((int)((uint)(ushort)local_158.revents << 0x1f) < 0)) &&
           (sVar5 = read(iVar2,auStack_150 + len,0x20 - len), 0 < sVar5)) {
          len = len + sVar5;
        }
      }
LAB_0010390a:
      close(iVar2);
    }
    uVar8 = uVar8 + 1;
  } while (uVar8 < 3 && (int)len < 0x20);
  path = *DAT_00103a00;
  ppcVar7 = DAT_00103a00;
  while (path != (char *)0x0) {
    if (0x1f < (int)len) goto LAB_001039d8;
    iVar2 = RAND_query_egd_bytes(path,auStack_150 + len,0x20 - len);
    if (0 < iVar2) {
      len = len + iVar2;
    }
    ppcVar7 = ppcVar7 + 1;
    path = *ppcVar7;
  }
  if (len != 0) {
LAB_001039d8:
    RAND_add(auStack_150,0x20,(double)CONCAT44(_Var1,in_stack_fffffe98));
    OPENSSL_cleanse(auStack_150,len);
  }
  local_15c = _Var1;
  RAND_add(&local_15c,4,(double)CONCAT44(_Var1,in_stack_fffffe98));
  local_15c = getuid();
  RAND_add(&local_15c,4,(double)CONCAT44(_Var1,in_stack_fffffe98));
  local_15c = time((time_t *)0x0);
  RAND_add(&local_15c,4,(double)CONCAT44(_Var1,in_stack_fffffe98));
  return 1;
}

