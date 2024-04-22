
int unpack(scanner_t *s,json_t *root,va_list *ap)

{
  char *pcVar1;
  size_t sVar2;
  undefined4 *puVar3;
  char **ppcVar4;
  size_t **ppsVar5;
  json_int_t **ppjVar6;
  json_int_t *pjVar7;
  undefined4 uVar8;
  double **ppdVar9;
  double *pdVar10;
  int iVar11;
  double dVar12;
  json_int_t jVar13;
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
        ppdVar9 = (double **)ap->__ap;
        ap->__ap = ppdVar9 + 1;
        pdVar10 = *ppdVar9;
        if (root != (json_t *)0x0) {
          dVar12 = json_number_value(root);
          *pdVar10 = dVar12;
        }
      }
      iVar11 = 0;
    }
    else {
      set_error(s,"<validation>","Expected real or integer, got %s",type_names[root->type]);
      iVar11 = -1;
    }
    break;
  default:
    set_error(s,"<format>","Unexpected format character \'%c\'",(uint)(byte)(s->token).token);
    iVar11 = -1;
    break;
  case 'I':
    if ((root == (json_t *)0x0) || ((root != (json_t *)0x0 && (root->type == JSON_INTEGER)))) {
      if ((s->flags & 1) == 0) {
        ppjVar6 = (json_int_t **)ap->__ap;
        ap->__ap = ppjVar6 + 1;
        pjVar7 = *ppjVar6;
        if (root != (json_t *)0x0) {
          jVar13 = json_integer_value(root);
          *pjVar7 = jVar13;
        }
      }
      iVar11 = 0;
    }
    else {
      set_error(s,"<validation>","Expected integer, got %s",type_names[root->type]);
      iVar11 = -1;
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
    iVar11 = 0;
    break;
  case '[':
    iVar11 = unpack_array(s,root,ap);
    break;
  case 'b':
    if (((root == (json_t *)0x0) || ((root != (json_t *)0x0 && (root->type == JSON_TRUE)))) ||
       ((root != (json_t *)0x0 && (root->type == JSON_FALSE)))) {
      if ((s->flags & 1) == 0) {
        puVar3 = (undefined4 *)ap->__ap;
        ap->__ap = puVar3 + 1;
        if (root != (json_t *)0x0) {
          if ((root == (json_t *)0x0) || (root->type != JSON_TRUE)) {
            uVar8 = 0;
          }
          else {
            uVar8 = 1;
          }
          *(undefined4 *)*puVar3 = uVar8;
        }
      }
      iVar11 = 0;
    }
    else {
      set_error(s,"<validation>","Expected true or false, got %s",type_names[root->type]);
      iVar11 = -1;
    }
    break;
  case 'f':
    if ((root == (json_t *)0x0) || ((root != (json_t *)0x0 && (root->type == JSON_REAL)))) {
      if ((s->flags & 1) == 0) {
        ppdVar9 = (double **)ap->__ap;
        ap->__ap = ppdVar9 + 1;
        pdVar10 = *ppdVar9;
        if (root != (json_t *)0x0) {
          dVar12 = json_real_value(root);
          *pdVar10 = dVar12;
        }
      }
      iVar11 = 0;
    }
    else {
      set_error(s,"<validation>","Expected real, got %s",type_names[root->type]);
      iVar11 = -1;
    }
    break;
  case 'i':
    if ((root == (json_t *)0x0) || ((root != (json_t *)0x0 && (root->type == JSON_INTEGER)))) {
      if ((s->flags & 1) == 0) {
        puVar3 = (undefined4 *)ap->__ap;
        ap->__ap = puVar3 + 1;
        puVar3 = (undefined4 *)*puVar3;
        if (root != (json_t *)0x0) {
          jVar13 = json_integer_value(root);
          *puVar3 = (int)jVar13;
        }
      }
      iVar11 = 0;
    }
    else {
      set_error(s,"<validation>","Expected integer, got %s",type_names[root->type]);
      iVar11 = -1;
    }
    break;
  case 'n':
    if ((root == (json_t *)0x0) || ((root != (json_t *)0x0 && (root->type == JSON_NULL)))) {
      iVar11 = 0;
    }
    else {
      set_error(s,"<validation>","Expected null, got %s",type_names[root->type]);
      iVar11 = -1;
    }
    break;
  case 's':
    if ((root == (json_t *)0x0) || ((root != (json_t *)0x0 && (root->type == JSON_STRING)))) {
      if ((s->flags & 1) == 0) {
        len_target = (size_t *)0x0;
        puVar3 = (undefined4 *)ap->__ap;
        ap->__ap = puVar3 + 1;
        ppcVar4 = (char **)*puVar3;
        if (ppcVar4 == (char **)0x0) {
          set_error(s,"<args>","NULL string argument");
          return -1;
        }
        next_token(s);
        if ((s->token).token == '%') {
          ppsVar5 = (size_t **)ap->__ap;
          ap->__ap = ppsVar5 + 1;
          len_target = *ppsVar5;
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
          *ppcVar4 = pcVar1;
          if (len_target != (size_t *)0x0) {
            sVar2 = json_string_length(root);
            *len_target = sVar2;
          }
        }
      }
      iVar11 = 0;
    }
    else {
      set_error(s,"<validation>","Expected string, got %s",type_names[root->type]);
      iVar11 = -1;
    }
    break;
  case '{':
    iVar11 = unpack_object(s,root,ap);
  }
  return iVar11;
}

