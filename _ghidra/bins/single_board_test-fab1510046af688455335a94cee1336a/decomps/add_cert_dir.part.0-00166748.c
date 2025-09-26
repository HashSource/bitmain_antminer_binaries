
undefined4 add_cert_dir_part_0(int param_1,char *param_2,int param_3)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  size_t sVar4;
  int *data;
  _STACK *p_Var5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  size_t __n;
  char *__s2;
  
  __s2 = param_2;
  do {
    do {
      pcVar8 = param_2;
      param_2 = pcVar8 + 1;
      cVar1 = *pcVar8;
    } while (cVar1 != ':' && cVar1 != '\0');
    __n = (int)pcVar8 - (int)__s2;
    if (__n != 0) {
      for (iVar6 = 0; iVar2 = sk_num(*(_STACK **)(param_1 + 4)), iVar6 < iVar2; iVar6 = iVar6 + 1) {
        puVar3 = (undefined4 *)sk_value(*(_STACK **)(param_1 + 4),iVar6);
        pcVar7 = (char *)*puVar3;
        sVar4 = strlen(pcVar7);
        if ((sVar4 == __n) && (iVar2 = strncmp(pcVar7,__s2,__n), iVar2 == 0)) break;
      }
      iVar2 = sk_num(*(_STACK **)(param_1 + 4));
      if (iVar2 <= iVar6) {
        if (*(int *)(param_1 + 4) == 0) {
          p_Var5 = sk_new_null();
          *(_STACK **)(param_1 + 4) = p_Var5;
          if (p_Var5 == (_STACK *)0x0) {
            ERR_put_error(0xb,100,0x41,"by_dir.c",0xe5);
            return 0;
          }
        }
        data = (int *)CRYPTO_malloc(0xc,"by_dir.c",0xe9);
        if (data == (int *)0x0) {
          return 0;
        }
        data[1] = param_3;
        p_Var5 = sk_new((cmp *)0x166365);
        data[2] = (int)p_Var5;
        pcVar7 = (char *)CRYPTO_malloc(__n + 1,"by_dir.c",0xee);
        *data = (int)pcVar7;
        if (pcVar7 == (char *)0x0) goto LAB_0016683c;
        if (data[2] != 0) {
          strncpy(pcVar7,__s2,__n);
          *(undefined1 *)(*data + __n) = 0;
          iVar6 = sk_push(*(_STACK **)(param_1 + 4),data);
          if (iVar6 != 0) goto LAB_00166804;
          pcVar7 = (char *)*data;
          if (pcVar7 == (char *)0x0) goto LAB_0016683c;
        }
        CRYPTO_free(pcVar7);
LAB_0016683c:
        if ((_STACK *)data[2] != (_STACK *)0x0) {
          sk_pop_free((_STACK *)data[2],(func *)0x166381);
        }
        CRYPTO_free(data);
        return 0;
      }
LAB_00166804:
      cVar1 = *pcVar8;
    }
    __s2 = param_2;
    if (cVar1 == '\0') {
      return 1;
    }
  } while( true );
}

