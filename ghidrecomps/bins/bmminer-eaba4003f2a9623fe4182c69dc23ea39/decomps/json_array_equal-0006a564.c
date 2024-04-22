
int json_array_equal(json_t *array1,json_t *array2)

{
  size_t sVar1;
  size_t sVar2;
  json_t *json1;
  json_t *json2;
  int iVar3;
  json_t *array2_local;
  json_t *array1_local;
  json_t *value2;
  json_t *value1;
  size_t size;
  size_t i;
  
  sVar1 = json_array_size(array1);
  sVar2 = json_array_size(array2);
  if (sVar2 == sVar1) {
    for (i = 0; i < sVar1; i = i + 1) {
      json1 = json_array_get(array1,i);
      json2 = json_array_get(array2,i);
      iVar3 = json_equal(json1,json2);
      if (iVar3 == 0) {
        return 0;
      }
    }
    iVar3 = 1;
  }
  else {
    iVar3 = 0;
  }
  return iVar3;
}

