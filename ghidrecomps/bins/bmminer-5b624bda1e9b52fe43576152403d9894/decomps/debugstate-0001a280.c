
/* WARNING: Unknown calling convention */

void debugstate(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  _Bool *p_Var1;
  _Bool *p_Var2;
  _Bool *p_Var3;
  _Bool *p_Var4;
  _Bool *p_Var5;
  _Bool *p_Var6;
  _Bool _Var7;
  _Bool io_open;
  __int32_t **pp_Var8;
  api_data *paVar9;
  char cVar10;
  
  if (param == (char *)0x0) goto switchD_0001a2a2_caseD_65;
  pp_Var8 = __ctype_tolower_loc();
  cVar10 = *(char *)(*pp_Var8 + (byte)*param);
  *param = cVar10;
  p_Var6 = DAT_0001a46c;
  p_Var5 = DAT_0001a464;
  p_Var4 = DAT_0001a45c;
  p_Var3 = DAT_0001a43c;
  p_Var2 = DAT_0001a438;
  p_Var1 = DAT_0001a434;
  switch(cVar10) {
  case 'd':
    cVar10 = *DAT_0001a434 ^ 1;
    *DAT_0001a434 = (_Bool)cVar10;
    *p_Var2 = (_Bool)cVar10;
    goto joined_r0x0001a42c;
  case 'n':
    *DAT_0001a438 = false;
    *p_Var1 = false;
    *p_Var3 = false;
    *p_Var4 = false;
    *p_Var5 = false;
    *p_Var6 = false;
    break;
  case 'p':
    _Var7 = *DAT_0001a464;
    *DAT_0001a464 = (_Bool)(_Var7 ^ 1U);
    *p_Var2 = (_Bool)(_Var7 ^ 1U);
    break;
  case 'q':
    *DAT_0001a43c = (_Bool)(*DAT_0001a43c ^ 1);
    break;
  case 'r':
    _Var7 = *DAT_0001a45c;
    *DAT_0001a45c = (_Bool)(_Var7 ^ 1U);
    if ((_Bool)(_Var7 ^ 1U) == false) break;
    goto LAB_0001a2de;
  case 's':
    *DAT_0001a448 = true;
    break;
  case 'v':
    cVar10 = *DAT_0001a438 ^ 1;
    *DAT_0001a438 = (_Bool)cVar10;
joined_r0x0001a42c:
    if (cVar10 != '\0') {
LAB_0001a2de:
      *DAT_0001a43c = false;
    }
    break;
  case 'w':
    *DAT_0001a46c = (_Bool)(*DAT_0001a46c ^ 1);
  }
switchD_0001a2a2_caseD_65:
  message(io_data,0x4f,0,(char *)0x0,isjson);
  if (isjson) {
    _Var7 = io_add(io_data,DAT_0001a440);
    paVar9 = api_add_bool((api_data *)0x0,DAT_0001a444,DAT_0001a448,false);
    paVar9 = api_add_bool(paVar9,DAT_0001a44c,DAT_0001a43c,false);
    paVar9 = api_add_bool(paVar9,DAT_0001a450,DAT_0001a438,false);
    paVar9 = api_add_bool(paVar9,DAT_0001a454,DAT_0001a434,false);
    paVar9 = api_add_bool(paVar9,DAT_0001a458,DAT_0001a45c,false);
    paVar9 = api_add_bool(paVar9,DAT_0001a460,DAT_0001a464,false);
    paVar9 = api_add_bool(paVar9,DAT_0001a468,DAT_0001a46c,false);
    print_data(io_data,paVar9,true,false);
    if (_Var7) {
      io_data->close = true;
    }
    return;
  }
  io_add(io_data,DAT_0001a470);
  paVar9 = api_add_bool((api_data *)0x0,DAT_0001a444,DAT_0001a448,isjson);
  paVar9 = api_add_bool(paVar9,DAT_0001a44c,DAT_0001a43c,isjson);
  paVar9 = api_add_bool(paVar9,DAT_0001a450,DAT_0001a438,isjson);
  paVar9 = api_add_bool(paVar9,DAT_0001a454,DAT_0001a434,isjson);
  paVar9 = api_add_bool(paVar9,DAT_0001a458,DAT_0001a45c,isjson);
  paVar9 = api_add_bool(paVar9,DAT_0001a460,DAT_0001a464,isjson);
  paVar9 = api_add_bool(paVar9,DAT_0001a468,DAT_0001a46c,isjson);
  print_data(io_data,paVar9,isjson,isjson);
  return;
}

