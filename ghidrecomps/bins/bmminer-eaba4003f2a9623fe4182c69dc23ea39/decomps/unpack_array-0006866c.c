
int unpack_array(scanner_t *s,json_t *root,va_list *ap)

{
  char *pcVar1;
  size_t sVar2;
  int iVar3;
  undefined4 uVar4;
  va_list *ap_local;
  json_t *root_local;
  scanner_t *s_local;
  long diff;
  json_t *value;
  int strict;
  size_t i;
  
  i = 0;
  strict = 0;
  if ((root == (json_t *)0x0) || ((root != (json_t *)0x0 && (root->type == JSON_ARRAY)))) {
    next_token(s);
    while ((s->token).token != ']') {
      if (strict != 0) {
        if (strict == 1) {
          uVar4 = 0x21;
        }
        else {
          uVar4 = 0x2a;
        }
        set_error(s,"<format>","Expected \']\' after \'%c\', got \'%c\'",uVar4,
                  (uint)(byte)(s->token).token);
        return -1;
      }
      if ((s->token).token == '\0') {
        set_error(s,"<format>","Unexpected end of format string");
        return -1;
      }
      if (((s->token).token == '!') || ((s->token).token == '*')) {
        if ((s->token).token == '!') {
          strict = 1;
        }
        else {
          strict = -1;
        }
        next_token(s);
      }
      else {
        pcVar1 = strchr("{[siIbfFOon",(uint)(byte)(s->token).token);
        if (pcVar1 == (char *)0x0) {
          set_error(s,"<format>","Unexpected format character \'%c\'",(uint)(byte)(s->token).token);
          return -1;
        }
        if (root == (json_t *)0x0) {
          value = (json_t *)0x0;
        }
        else {
          value = json_array_get(root,i);
          if (value == (json_t *)0x0) {
            set_error(s,"<validation>","Array index %lu out of range",i);
            return -1;
          }
        }
        iVar3 = unpack(s,value,ap);
        if (iVar3 != 0) {
          return -1;
        }
        next_token(s);
        i = i + 1;
      }
    }
    if ((strict == 0) && ((s->flags & 2) != 0)) {
      strict = 1;
    }
    if (((root == (json_t *)0x0) || (strict != 1)) || (sVar2 = json_array_size(root), sVar2 == i)) {
      iVar3 = 0;
    }
    else {
      sVar2 = json_array_size(root);
      set_error(s,"<validation>","%li array item(s) left unpacked",sVar2 - i);
      iVar3 = -1;
    }
  }
  else {
    set_error(s,"<validation>","Expected array, got %s",type_names[root->type]);
    iVar3 = -1;
  }
  return iVar3;
}

