
int json_string_equal(json_t *string1,json_t *string2)

{
  int iVar1;
  json_t *string2_local;
  json_t *string1_local;
  json_string_t *s2;
  json_string_t *s1;
  
  if ((((string1 == (json_t *)0x0) || (string1->type != JSON_STRING)) || (string2 == (json_t *)0x0))
     || (string2->type != JSON_STRING)) {
    iVar1 = 0;
  }
  else if ((string1[1].refcount == string2[1].refcount) &&
          (iVar1 = memcmp((void *)string1[1].type,(void *)string2[1].type,string1[1].refcount),
          iVar1 == 0)) {
    iVar1 = 1;
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}

