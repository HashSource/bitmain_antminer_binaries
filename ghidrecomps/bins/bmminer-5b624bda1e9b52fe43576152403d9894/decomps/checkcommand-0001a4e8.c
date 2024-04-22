
/* WARNING: Unknown calling convention */

void checkcommand(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  char *pcVar1;
  _Bool _Var2;
  _Bool io_open;
  char *__s1;
  int iVar3;
  __int32_t **pp_Var4;
  api_data *paVar5;
  api_data *root;
  char *pcVar6;
  int __res;
  char *data;
  undefined uVar7;
  __int32_t *p_Var8;
  char **ppcVar9;
  _Bool access;
  char *pcVar10;
  char cmdbuf [100];
  
  if ((param == (char *)0x0) || (*param == '\0')) {
    message(io_data,0x47,0,(char *)0x0,isjson);
  }
  else {
    __s1 = *(char **)(DAT_0001a5dc + 0x440);
    pcVar10 = __s1;
    if (__s1 != (char *)0x0) {
      ppcVar9 = (char **)(DAT_0001a5dc + 0x440);
      do {
        iVar3 = strcmp(__s1,param);
        if (iVar3 == 0) {
          sprintf(cmdbuf,DAT_0001a5e0,param);
          pp_Var4 = __ctype_toupper_loc();
          p_Var8 = *pp_Var4;
          if (p_Var8[(byte)group] != p_Var8[0x57]) {
            __s1 = strstr(*(char **)(DAT_0001a5e4 + (p_Var8[(byte)group] - p_Var8[0x41]) * 4),cmdbuf
                         );
            pcVar10 = (char *)0x1;
            if (__s1 == (char *)0x0) break;
          }
          __s1 = (char *)0x1;
          pcVar10 = (char *)0x1;
          break;
        }
        ppcVar9 = ppcVar9 + 3;
        __s1 = *ppcVar9;
        pcVar10 = __s1;
      } while (__s1 != (char *)0x0);
    }
    message(io_data,0x48,0,(char *)0x0,isjson);
    pcVar1 = DAT_0001a5f4;
    data = DAT_0001a5f0;
    pcVar6 = DAT_0001a5ec;
    if (isjson) {
      pcVar6 = DAT_0001a5e8;
    }
    _Var2 = io_add(io_data,pcVar6);
    pcVar6 = data;
    if (pcVar10 != (char *)0x0) {
      pcVar6 = pcVar1;
    }
    paVar5 = api_add_const((api_data *)0x0,DAT_0001a5f8,pcVar6,false);
    if (__s1 != (char *)0x0) {
      data = pcVar1;
    }
    paVar5 = api_add_const(paVar5,DAT_0001a5fc,data,false);
    uVar7 = 0;
    print_data(io_data,paVar5,isjson,false);
    if (_Var2 && isjson) {
      uVar7 = true;
    }
    if (_Var2 && isjson) {
      io_data->close = (_Bool)uVar7;
    }
  }
  return;
}

