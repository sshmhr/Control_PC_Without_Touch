long time;
int distance, left_distance, right_distance;
const int trigger_pin_sensor_1 = 2;
const int trigger_pin_sensor_2 = 4;
const int echo_pin_sensor_1 = 3;
const int echo_pin_sensor_2 = 5;

void initial_setup_pin_type()
{

  Serial.begin(9600);
  pinMode(trigger_pin_sensor_1, OUTPUT);
  pinMode(trigger_pin_sensor_2, OUTPUT);
  pinMode(echo_pin_sensor_1, INPUT);
  pinMode(echo_pin_sensor_2, INPUT);
}

void find_distance_from_sensor(int trigger, int echo)
{

  digitalWrite(trigger, LOW);
  delayMicroseconds(4);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(15);
  digitalWrite(trigger, LOW);

  time = pulseIn(echo, HIGH);
  distance = time * 0.017;
  if (distance > 70)
    distance = 70;
}

void loop()
{

  find_distance_from_sensor(trigger_pin_sensor_2, echo_pin_sensor_2);
  right_distance = distance;

  find_distance_from_sensor(trigger_pin_sensor_1, echo_pin_sensor_1);
  left_distance = distance;

  if ((left_distance > 50 && right_distance > 50) && (left_distance < 70 && right_distance < 70))
  {
    // both hands at a far distance
    Serial.println("both_far");
    delay(600);
  }

  if ((left_distance >= 12 && left_distance <= 23) && (right_distance >= 12 && right_distance <= 23))
  {
    // both hands near
    Serial.println("both_near");
    delay(600);
  }

  find_distance_from_sensor(trigger_pin_sensor_2, echo_pin_sensor_2);
  right_distance = distance;
  find_distance_from_sensor(trigger_pin_sensor_1, echo_pin_sensor_1);
  left_distance = distance;

  if (right_distance >= 12 && right_distance <= 23)
  {
    delay(130);
    find_distance_from_sensor(trigger_pin_sensor_2, echo_pin_sensor_2);
    right_distance = distance;
    if (right_distance >= 12 && right_distance <= 23)
    {
      Serial.println("right_hand_near");
      while (right_distance <= 50)
      {
        find_distance_from_sensor(trigger_pin_sensor_2, echo_pin_sensor_2);
        right_distance = distance;
        if (right_distance < 11)
        {
          Serial.println("right_hand_in");
          delay(400);
        }
        if (right_distance > 25)
        {
          Serial.println("right_hand_out");
          delay(400);
        }
      }
    }
  }

  if (left_distance >= 12 && left_distance <= 23)
  {
    // Make sure that left hand is stable and is near
    delay(130);
    find_distance_from_sensor(trigger_pin_sensor_1, echo_pin_sensor_1);
    left_distance = distance;
    if (left_distance >= 12 && left_distance <= 23)
    {
      Serial.println("left_hand_near");
      while (left_distance <= 50)
      {
        find_distance_from_sensor(trigger_pin_sensor_1, echo_pin_sensor_1);
        left_distance = distance;
        if (left_distance < 11)
        {
          Serial.println("left_hand_in");
          delay(400);
        }
        if (left_distance > 25)
        {
          Serial.println("left_hand_out");
          delay(400);
        }
      }
    }
  }

  delay(250);
}