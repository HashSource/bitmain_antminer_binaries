
json_t * json_integer_copy(json_t *integer)

{
  json_t *pjVar1;
  json_int_t value;
  json_t *integer_local;
  
  value = json_integer_value(integer);
  pjVar1 = json_integer(value);
  return pjVar1;
}

