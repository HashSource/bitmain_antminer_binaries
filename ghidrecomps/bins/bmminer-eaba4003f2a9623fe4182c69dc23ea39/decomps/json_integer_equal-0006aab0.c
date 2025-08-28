
int json_integer_equal(json_t *integer1,json_t *integer2)

{
  json_int_t jVar1;
  json_int_t jVar2;
  json_t *integer2_local;
  json_t *integer1_local;
  
  jVar1 = json_integer_value(integer1);
  jVar2 = json_integer_value(integer2);
  return (uint)(jVar1 == jVar2);
}

