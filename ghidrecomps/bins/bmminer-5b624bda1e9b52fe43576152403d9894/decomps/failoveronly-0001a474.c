
/* WARNING: Unknown calling convention */

void failoveronly(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  byte bVar1;
  char cVar2;
  __int32_t **pp_Var3;
  
  if ((param != (char *)0x0) && (bVar1 = *param, bVar1 != 0)) {
    pp_Var3 = __ctype_tolower_loc();
    cVar2 = (char)(*pp_Var3)[bVar1];
    *param = cVar2;
    if (cVar2 != 'f' && cVar2 != 't') {
      message(io_data,0x4c,0,(char *)0x0,isjson);
      return;
    }
    opt_fail_only = cVar2 == 't';
    message(io_data,0x4d,(uint)opt_fail_only,(char *)0x0,isjson);
    return;
  }
  message(io_data,0x4b,0,(char *)0x0,isjson);
  return;
}

