
int unpack(scanner_t *s,json_t *root,va_list *ap)

{
  char *pcVar1;
  size_t sVar2;
  undefined4 *puVar3;
  int *piVar4;
  json_int_t *pjVar5;
  undefined4 uVar6;
  double *pdVar7;
  int iVar8;
  double dVar9;
  json_int_t jVar10;
  va_list *ap_local;
  json_t *root_local;
  scanner_t *s_local;
  json_t **target_5;
  double *target_4;
  double *target_3;
  int *target_2;
  json_int_t *target_1;
  int *target;
  char **str_target;
  size_t *len_target;
  
  switch((s->token).token) {
  case 'F':
    if (((root == (json_t *)0x0) || ((root != (json_t *)0x0 && (root->type == JSON_INTEGER)))) ||
       ((root != (json_t *)0x0 && (root->type == JSON_REAL)))) {
      if ((s->flags & 1) == 0) {
        puVar3 = (undefined4 *)ap->__ap;
        ap->__ap = puVar3 + 1;
        pdVar7 = (double *)*puVar3;
        if (root != (json_t *)0x0) {
          dVar9 = json_number_value(root);
          *pdVar7 = dVar9;
        }
      }
      iVar8 = 0;
    }
    else {
      set_error(s,"<validation>","Expected real or integer, got %s",type_names[root->type]);
      iVar8 = -1;
    }
    break;
  default:
    set_error(s,"<format>","Unexpected format character \'%c\'",(uint)(byte)(s->token).token);
    iVar8 = -1;
    break;
  case 'I':
    if ((root == (json_t *)0x0) || ((root != (json_t *)0x0 && (root->type == JSON_INTEGER)))) {
      if ((s->flags & 1) == 0) {
        puVar3 = (undefined4 *)ap->__ap;
        ap->__ap = puVar3 + 1;
        pjVar5 = (json_int_t *)*puVar3;
        if (root != (json_t *)0x0) {
          jVar10 = json_integer_value(root);
          *pjVar5 = jVar10;
        }
      }
      iVar8 = 0;
    }
    else {
      set_error(s,"<validation>","Expected integer, got %s",type_names[root->type]);
      iVar8 = -1;
    }
    break;
  case 'O':
    if ((root != (json_t *)0x0) && ((s->flags & 1) == 0)) {
      json_incref(root);
    }
  case 'o':
    if ((s->flags & 1) == 0) {
      puVar3 = (undefined4 *)ap->__ap;
      ap->__ap = puVar3 + 1;
      if (root != (json_t *)0x0) {
        *(json_t **)*puVar3 = root;
      }
    }
    iVar8 = 0;
    break;
  case '[':
    iVar8 = unpack_array(s,root,ap);
    break;
  case 'b':
    if (((root == (json_t *)0x0) || ((root != (json_t *)0x0 && (root->type == JSON_TRUE)))) ||
       ((root != (json_t *)0x0 && (root->type == JSON_FALSE)))) {
      if ((s->flags & 1) == 0) {
        puVar3 = (undefined4 *)ap->__ap;
        ap->__ap = puVar3 + 1;
        if (root != (json_t *)0x0) {
          if ((root == (json_t *)0x0) || (root->type != JSON_TRUE)) {
            uVar6 = 0;
          }
          else {
            uVar6 = 1;
          }
          *(undefined4 *)*puVar3 = uVar6;
        }
      }
      iVar8 = 0;
    }
    else {
      set_error(s,"<validation>","Expected true or false, got %s",type_names[root->type]);
      iVar8 = -1;
    }
    break;
  case 'f':
    if ((root == (json_t *)0x0) || ((root != (json_t *)0x0 && (root->type == JSON_REAL)))) {
      if ((s->flags & 1) == 0) {
        puVar3 = (undefined4 *)ap->__ap;
        ap->__ap = puVar3 + 1;
        pdVar7 = (double *)*puVar3;
        if (root != (json_t *)0x0) {
          dVar9 = json_real_value(root);
          *pdVar7 = dVar9;
        }
      }
      iVar8 = 0;
    }
    else {
      set_error(s,"<validation>","Expected real, got %s",type_names[root->type]);
      iVar8 = -1;
    }
    break;
  case 'i':
    if ((root == (json_t *)0x0) || ((root != (json_t *)0x0 && (root->type == JSON_INTEGER)))) {
      if ((s->flags & 1) == 0) {
        puVar3 = (undefined4 *)ap->__ap;
        ap->__ap = puVar3 + 1;
        puVar3 = (undefined4 *)*puVar3;
        if (root != (json_t *)0x0) {
          jVar10 = json_integer_value(root);
          *puVar3 = (int)jVar10;
        }
      }
      iVar8 = 0;
    }
    else {
      set_error(s,"<validation>","Expected integer, got %s",type_names[root->type]);
      iVar8 = -1;
    }
    break;
  case 'n':
    if ((root == (json_t *)0x0) || ((root != (json_t *)0x0 && (root->type == JSON_NULL)))) {
      iVar8 = 0;
    }
    else {
      set_error(s,"<validation>","Expected null, got %s",type_names[root->type]);
      iVar8 = -1;
    }
    break;
  case 's':
    if ((root == (json_t *)0x0) || ((root != (json_t *)0x0 && (root->type == JSON_STRING)))) {
      if ((s->flags & 1) == 0) {
        len_target = (size_t *)0x0;
        puVar3 = (undefined4 *)ap->__ap;
        ap->__ap = puVar3 + 1;
        puVar3 = (undefined4 *)*puVar3;
        if (puVar3 == (undefined4 *)0x0) {
          set_error(s,"<args>","NULL string argument");
          return -1;
        }
        next_token(s);
        if ((s->token).token == '%') {
          piVar4 = (int *)ap->__ap;
          ap->__ap = piVar4 + 1;
          len_target = (size_t *)*piVar4;
          if (len_target == (size_t *)0x0) {
            set_error(s,"<args>","NULL string length argument");
            return -1;
          }
        }
        else {
          prev_token(s);
        }
        if (root != (json_t *)0x0) {
          pcVar1 = json_string_value(root);
          *puVar3 = pcVar1;
          if (len_target != (size_t *)0x0) {
            sVar2 = json_string_length(root);
            *len_target = sVar2;
          }
        }
      }
      iVar8 = 0;
    }
    else {
      set_error(s,"<validation>","Expected string, got %s",type_names[root->type]);
      iVar8 = -1;
    }
    break;
  case '{':
    iVar8 = unpack_object(s,root,ap);
  }
  return iVar8;
}

