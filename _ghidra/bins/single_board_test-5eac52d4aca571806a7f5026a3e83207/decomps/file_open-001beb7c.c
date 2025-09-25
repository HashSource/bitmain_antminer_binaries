
int * file_open(undefined4 param_1,char *param_2)

{
  int iVar1;
  int *piVar2;
  BIO_METHOD *type;
  BIO *pBVar3;
  BIO *append;
  long lVar4;
  int *piVar5;
  char *ptr;
  int iVar6;
  uint uVar7;
  char *pcVar8;
  uint uVar9;
  char *pcStack_1088;
  byte local_1084 [4];
  char *local_1080;
  stat sStack_1078;
  char acStack_1020 [4095];
  undefined1 local_21;
  
  local_1084[0] = local_1084[0] & 0xfe;
  pcStack_1088 = param_2;
  iVar1 = strncasecmp(param_2,"file:",5);
  if (iVar1 == 0) {
    pcVar8 = param_2 + 5;
    iVar1 = strncmp(pcVar8,"//",2);
    if (iVar1 == 0) {
      pcVar8 = param_2 + 7;
      iVar1 = strncasecmp(pcVar8,"localhost/",10);
      if (iVar1 == 0) {
        pcVar8 = param_2 + 0x10;
        uVar9 = 1;
        iVar1 = 0;
      }
      else {
        if (param_2[7] != '/') {
          ERR_put_error(0x2c,0x78,0x6f,"crypto/store/loader_file.c",0x33d);
          return (int *)0x0;
        }
        uVar9 = 1;
        iVar1 = 0;
      }
    }
    else {
      uVar9 = 2;
      iVar1 = 1;
    }
    *(char **)(local_1084 + iVar1 * 8 + -4) = pcVar8;
    local_1084[iVar1 * 8] = local_1084[iVar1 * 8] | 1;
    pcVar8 = pcStack_1088;
  }
  else {
    uVar9 = 1;
    pcVar8 = param_2;
  }
  uVar7 = 0;
  while( true ) {
    if (((int)((uint)local_1084[uVar7 * 8] << 0x1f) < 0) && (*pcVar8 != '/')) {
      ERR_put_error(0x2c,0x78,0x6c,"crypto/store/loader_file.c",0x35a);
      ERR_add_error_data(1,pcVar8);
      return (int *)0x0;
    }
    iVar1 = __xstat(3,pcVar8,&sStack_1078);
    if (-1 < iVar1) break;
    piVar2 = __errno_location();
    ERR_put_error(2,0x16,*piVar2,"crypto/store/loader_file.c",0x360);
    uVar7 = uVar7 + 1;
    ERR_add_error_data(1,pcVar8);
    pcVar8 = local_1080;
    if (uVar9 <= uVar7) {
      return (int *)0x0;
    }
  }
  if (pcVar8 == (char *)0x0) {
    return (int *)0x0;
  }
  ERR_clear_error();
  piVar2 = (int *)CRYPTO_zalloc(0x30,"crypto/store/loader_file.c",0x36d);
  if (piVar2 == (int *)0x0) {
    ERR_put_error(0x2c,0x78,0x41,"crypto/store/loader_file.c",0x36f);
    return (int *)0x0;
  }
  if ((sStack_1078.st_mode & 0xf000) == 0x4000) {
    ptr = CRYPTO_strdup(param_2,"crypto/store/loader_file.c",0x379);
    *piVar2 = 2;
    piVar2[5] = (int)ptr;
    if (ptr != (char *)0x0) {
      iVar1 = OPENSSL_DIR_read(piVar2 + 3,pcVar8);
      piVar2[9] = iVar1;
      piVar5 = __errno_location();
      iVar6 = *piVar5;
      piVar2[10] = iVar6;
      if (iVar1 != 0) {
        return piVar2;
      }
      if (iVar6 == 0) {
        piVar2[4] = 1;
        return piVar2;
      }
      ERR_put_error(0x2c,0x78,2,"crypto/store/loader_file.c",900);
      iVar1 = piVar2[10];
      *piVar5 = iVar1;
      iVar1 = openssl_strerror_r(iVar1,acStack_1020,0x100);
      if (iVar1 != 0) {
        ERR_add_error_data(1,acStack_1020);
      }
      goto LAB_001bed86;
    }
  }
  else {
    memset(acStack_1020,0,0x1000);
    type = BIO_f_buffer();
    pBVar3 = BIO_new(type);
    if (pBVar3 != (BIO *)0x0) {
      append = BIO_new_file(pcVar8,"rb");
      piVar2[3] = (int)append;
      if (append != (BIO *)0x0) {
        pBVar3 = BIO_push(pBVar3,append);
        piVar2[3] = (int)pBVar3;
        lVar4 = BIO_ctrl(pBVar3,0x1d,0xfff,acStack_1020);
        if (lVar4 < 1) {
          return piVar2;
        }
        local_21 = 0;
        pcVar8 = strstr(acStack_1020,"-----BEGIN ");
        if (pcVar8 != (char *)0x0) {
          *piVar2 = 1;
          return piVar2;
        }
        return piVar2;
      }
    }
    BIO_free_all(pBVar3);
LAB_001bed86:
    if (*piVar2 != 2) {
      if (piVar2[4] != 0) {
        (**(code **)(piVar2[4] + 0xc))(piVar2 + 5);
        piVar2[5] = 0;
        piVar2[4] = 0;
      }
      goto LAB_001bed9e;
    }
    ptr = (char *)piVar2[5];
  }
  CRYPTO_free(ptr);
LAB_001bed9e:
  CRYPTO_free(piVar2);
  return (int *)0x0;
}

