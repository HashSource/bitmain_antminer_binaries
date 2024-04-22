
int asn1_template_ex_i2d_constprop_2(_STACK **param_1,uchar **param_2,uint *param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  _STACK *p_Var3;
  int length;
  uint uVar4;
  int iVar5;
  uint tag;
  int local_48;
  uint local_44;
  uint local_40;
  int local_3c;
  uint local_38;
  uint local_34;
  void *local_2c [2];
  
  local_38 = *param_3;
  uVar4 = param_4 & 0xffffff3f;
  if ((local_38 & 0x18) == 0) {
    tag = 0xffffffff;
    local_44 = 0;
  }
  else {
    local_44 = local_38 & 0xc0;
    tag = param_3[1];
  }
  if ((int)(local_38 << 0x14) < 0) {
    if ((param_4 & 0x800) == 0) {
      iVar5 = 1;
    }
    else {
      iVar5 = 2;
    }
  }
  else {
    iVar5 = 1;
  }
  if ((local_38 & 6) == 0) {
    if (-1 < (int)(local_38 << 0x1b)) {
      iVar5 = ASN1_item_ex_i2d((ASN1_VALUE **)param_1,param_2,(ASN1_ITEM *)param_3[4],tag,
                               uVar4 | local_44);
      return iVar5;
    }
    iVar2 = ASN1_item_ex_i2d_constprop_0(param_1,param_3[4],uVar4);
    if (iVar2 == 0) {
      return 0;
    }
    local_48 = ASN1_object_size(iVar5,iVar2,tag);
    if (param_2 == (uchar **)0x0) {
      return local_48;
    }
    ASN1_put_object(param_2,iVar5,iVar2,tag,local_44);
    ASN1_item_ex_i2d_constprop_1(param_1,param_2,param_3[4],uVar4);
    if (iVar5 != 2) {
      return local_48;
    }
  }
  else {
    p_Var3 = *param_1;
    if (p_Var3 == (_STACK *)0x0) {
      return 0;
    }
    if ((local_38 & 2) == 0) {
      local_3c = 0;
    }
    else if ((local_38 & 4) == 0) {
      local_3c = 1;
    }
    else {
      local_3c = 2;
    }
    if ((tag == 0xffffffff) || ((local_38 & 0x10) != 0)) {
      local_34 = 0;
      if (local_3c == 0) {
        local_40 = 0x10;
      }
      else {
        local_40 = 0x11;
      }
    }
    else {
      local_34 = local_44;
      local_40 = tag;
    }
    local_38 = local_38 & 0x10;
    length = 0;
    iVar2 = 0;
    while( true ) {
      iVar1 = sk_num(p_Var3);
      if (iVar1 <= iVar2) break;
      local_2c[0] = sk_value(p_Var3,iVar2);
      iVar1 = ASN1_item_ex_i2d_constprop_0(local_2c,param_3[4],uVar4);
      length = length + iVar1;
      iVar2 = iVar2 + 1;
    }
    iVar2 = ASN1_object_size(iVar5,length,local_40);
    if (local_38 == 0) {
      local_48 = iVar2;
      if (param_2 == (uchar **)0x0) {
        return iVar2;
      }
    }
    else {
      local_48 = ASN1_object_size(iVar5,iVar2,tag);
      if (param_2 == (uchar **)0x0) {
        return local_48;
      }
      ASN1_put_object(param_2,iVar5,iVar2,tag,local_44);
    }
    ASN1_put_object(param_2,iVar5,length,local_40,local_34);
    asn1_set_seq_out(p_Var3,param_2,length,param_3[4],local_3c,uVar4);
    if (iVar5 != 2) {
      return local_48;
    }
    ASN1_put_eoc(param_2);
    if (local_38 == 0) {
      return local_48;
    }
  }
  ASN1_put_eoc(param_2);
  return local_48;
}

