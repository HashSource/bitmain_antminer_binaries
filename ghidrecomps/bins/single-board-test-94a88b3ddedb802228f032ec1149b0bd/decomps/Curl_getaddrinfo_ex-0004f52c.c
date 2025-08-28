
int Curl_getaddrinfo_ex(char *param_1,char *param_2,addrinfo *param_3,undefined4 *param_4)

{
  int iVar1;
  int *piVar2;
  void *__dest;
  int iVar3;
  int iVar4;
  int iVar5;
  addrinfo *paVar6;
  int *piVar7;
  int *piVar8;
  uint __n;
  addrinfo *local_2c [2];
  
  *param_4 = 0;
  iVar1 = getaddrinfo(param_1,param_2,param_3,local_2c);
  if (iVar1 == 0) {
    if (local_2c[0] == (addrinfo *)0x0) {
      iVar1 = -2;
      piVar8 = (int *)0x0;
    }
    else {
      piVar7 = (int *)0x0;
      piVar8 = (int *)0x0;
      paVar6 = local_2c[0];
LAB_0004f570:
      do {
        piVar2 = piVar8;
        if (paVar6->ai_family == 2) {
          __n = 0x10;
LAB_0004f57a:
          if (((paVar6->ai_addr != (sockaddr *)0x0) && (paVar6->ai_addrlen != 0)) &&
             (__n <= paVar6->ai_addrlen)) {
            piVar2 = (int *)(*Curl_cmalloc)(0x20);
            if (piVar2 == (int *)0x0) {
              iVar1 = -10;
              break;
            }
            iVar3 = paVar6->ai_family;
            iVar4 = paVar6->ai_protocol;
            *piVar2 = paVar6->ai_flags;
            iVar5 = paVar6->ai_socktype;
            piVar2[1] = iVar3;
            piVar2[3] = iVar4;
            piVar2[2] = iVar5;
            piVar2[4] = __n;
            piVar2[6] = 0;
            piVar2[5] = 0;
            piVar2[7] = 0;
            __dest = (void *)(*Curl_cmalloc)(__n);
            piVar2[6] = (int)__dest;
            if (__dest == (void *)0x0) {
              iVar1 = -10;
              (*Curl_cfree)(piVar2);
              break;
            }
            memcpy(__dest,paVar6->ai_addr,__n);
            if (paVar6->ai_canonname != (char *)0x0) {
              iVar3 = (*Curl_cstrdup)();
              piVar2[5] = iVar3;
              if (iVar3 == 0) {
                iVar1 = -10;
                (*Curl_cfree)(piVar2[6]);
                (*Curl_cfree)(piVar2);
                break;
              }
            }
            if (piVar7 == (int *)0x0) {
              piVar7 = piVar2;
            }
            if (piVar8 != (int *)0x0) {
              paVar6 = paVar6->ai_next;
              piVar8[7] = (int)piVar2;
              piVar8 = piVar2;
              if (paVar6 == (addrinfo *)0x0) break;
              goto LAB_0004f570;
            }
          }
        }
        else if (paVar6->ai_family == 10) {
          __n = 0x1c;
          goto LAB_0004f57a;
        }
        paVar6 = paVar6->ai_next;
        piVar8 = piVar2;
      } while (paVar6 != (addrinfo *)0x0);
      if (local_2c[0] != (addrinfo *)0x0) {
        freeaddrinfo(local_2c[0]);
      }
      if (iVar1 == 0) {
        piVar8 = piVar7;
        if (piVar7 == (int *)0x0) {
          iVar1 = -2;
        }
      }
      else {
        piVar8 = (int *)0x0;
        Curl_freeaddrinfo(piVar7);
      }
    }
    *param_4 = piVar8;
  }
  return iVar1;
}

