
/* WARNING: Unknown calling convention */

void failoveronly(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  byte bVar1;
  char cVar2;
  __int32_t **pp_Var3;
  _Bool tf;
  
  if ((param != (char *)0x0) && (bVar1 = *param, bVar1 != 0)) {
    pp_Var3 = __ctype_tolower_loc();
    cVar2 = *(char *)(*pp_Var3 + bVar1);
    *param = cVar2;
    if (cVar2 != 'f' && cVar2 != 't') {
      message(io_data,0x4c,0,(char *)0x0,isjson);
      return;
    }
    *(bool *)DAT_0001a4e4 = cVar2 == 't';
    message(io_data,0x4d,(uint)(cVar2 == 't'),(char *)0x0,isjson);
    return;
  }
  message(io_data,0x4b,0,(char *)0x0,isjson);
  return;
}

