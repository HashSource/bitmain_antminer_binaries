
int json_equal(json_t *json1,json_t *json2)

{
  int iVar1;
  json_t *json2_local;
  json_t *json1_local;
  
  if ((json1 == (json_t *)0x0) || (json2 == (json_t *)0x0)) {
    iVar1 = 0;
  }
  else if (json1->type == json2->type) {
    if (json1 == json2) {
      iVar1 = 1;
    }
    else {
      switch(json1->type) {
      case JSON_OBJECT:
        iVar1 = json_object_equal(json1,json2);
        break;
      case JSON_ARRAY:
        iVar1 = json_array_equal(json1,json2);
        break;
      case JSON_STRING:
        iVar1 = json_string_equal(json1,json2);
        break;
      case JSON_INTEGER:
        iVar1 = json_integer_equal(json1,json2);
        break;
      case JSON_REAL:
        iVar1 = json_real_equal(json1,json2);
        break;
      default:
        iVar1 = 0;
      }
    }
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}

