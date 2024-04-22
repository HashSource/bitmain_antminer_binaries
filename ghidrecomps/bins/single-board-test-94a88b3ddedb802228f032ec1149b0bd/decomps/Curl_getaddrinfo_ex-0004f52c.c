
int Curl_getaddrinfo_ex(char *param_1,char *param_2,addrinfo *param_3,int **param_4)

{
  code **ppcVar1;
  code **ppcVar2;
  int iVar3;
  int *piVar4;
  void *__dest;
  int iVar5;
  int iVar6;
  int iVar7;
  addrinfo *paVar8;
  int *piVar9;
  int *piVar10;
  size_t __n;
  addrinfo *local_2c [2];
  
  *param_4 = (int *)0x0;
  iVar3 = getaddrinfo(param_1,param_2,param_3,local_2c);
  ppcVar2 = DAT_0004f668;
  if (iVar3 == 0) {
    if (local_2c[0] == (addrinfo *)0x0) {
      iVar3 = -2;
      piVar10 = (int *)0x0;
    }
    else {
      piVar9 = (int *)0x0;
      piVar10 = (int *)0x0;
      paVar8 = local_2c[0];
LAB_0004f570:
      do {
        piVar4 = piVar10;
        if (paVar8->ai_family == 2) {
          __n = 0x10;
LAB_0004f57a:
          if (((paVar8->ai_addr != (sockaddr *)0x0) && (paVar8->ai_addrlen != 0)) &&
             (__n <= paVar8->ai_addrlen)) {
            piVar4 = (int *)(**ppcVar2)(0x20);
            if (piVar4 == (int *)0x0) {
              iVar3 = -10;
              break;
            }
            iVar5 = paVar8->ai_family;
            iVar6 = paVar8->ai_protocol;
            *piVar4 = paVar8->ai_flags;
            iVar7 = paVar8->ai_socktype;
            piVar4[1] = iVar5;
            piVar4[3] = iVar6;
            piVar4[2] = iVar7;
            piVar4[4] = __n;
            piVar4[6] = 0;
            piVar4[5] = 0;
            piVar4[7] = 0;
            __dest = (void *)(**ppcVar2)(__n);
            piVar4[6] = (int)__dest;
            if (__dest == (void *)0x0) {
              iVar3 = -10;
              (**DAT_0004f664)(piVar4);
              break;
            }
            memcpy(__dest,paVar8->ai_addr,__n);
            if (paVar8->ai_canonname != (char *)0x0) {
              iVar5 = (*Curl_cstrdup)();
              piVar4[5] = iVar5;
              ppcVar1 = DAT_0004f664;
              if (iVar5 == 0) {
                iVar3 = -10;
                (**DAT_0004f664)(piVar4[6]);
                (**ppcVar1)(piVar4);
                break;
              }
            }
            if (piVar9 == (int *)0x0) {
              piVar9 = piVar4;
            }
            if (piVar10 != (int *)0x0) {
              paVar8 = paVar8->ai_next;
              piVar10[7] = (int)piVar4;
              piVar10 = piVar4;
              if (paVar8 == (addrinfo *)0x0) break;
              goto LAB_0004f570;
            }
          }
        }
        else if (paVar8->ai_family == 10) {
          __n = 0x1c;
          goto LAB_0004f57a;
        }
        paVar8 = paVar8->ai_next;
        piVar10 = piVar4;
      } while (paVar8 != (addrinfo *)0x0);
      if (local_2c[0] != (addrinfo *)0x0) {
        freeaddrinfo(local_2c[0]);
      }
      if (iVar3 == 0) {
        piVar10 = piVar9;
        if (piVar9 == (int *)0x0) {
          iVar3 = -2;
        }
      }
      else {
        piVar10 = (int *)0x0;
        Curl_freeaddrinfo(piVar9);
      }
    }
    *param_4 = piVar10;
  }
  return iVar3;
}

