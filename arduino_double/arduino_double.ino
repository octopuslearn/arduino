
#define button1 2
#define jiguang A2


const int arr1_size = 10;
int arr1[arr1_size] = {0};


void setup() {
  Serial.begin(9600);
  pinMode(button1, INPUT_PULLUP);
  pinMode(jiguang, INPUT);
}

void loop() {
  if(digitalRead(button1) == LOW)
  {
    for(int i = 0;i < arr1_size;i++)
    {
      arr1[i] = analogRead(jiguang);
      delay(50);
    }
    Serial.print("Befor Sorting ");
    printArray(arr1, arr1_size);//打印读取到的额数据

    getValue(arr1, arr1_size, true);//


/*以下，为啥这样就可以更改，数值顺序，因为指针吗*/
    // bubbleSort(arr1, arr1_size);//气泡排序
    // Serial.print("After Sorting ");
    // printArray(arr1, arr1_size);//打印读取到的额数据
/*以上，为啥这样就可以更改，数值顺序，因为指针吗*/
  }


  // put your main code here, to run repeatedly:
}



//气泡排序 
//第一轮，所需次数size-1
void bubbleSort(int array1[], int size)
{
  for(int onner = 0;onner < size-1; ++onner)
  {
    for(int inner = 0;inner <size - 1 - onner;++inner)
    {
      if(array1[inner] > array1[inner + 1])
      {
        int temp = array1[inner];
        array1[inner] = array1[inner + 1];
        array1[inner + 1] = temp;
      }
    }
  }
}




int getValue(int array1[], int size, bool printlog)
{
  bubbleSort(array1, size);//气泡排序

  if(printlog)
  {
    Serial.print("After Sorting ");
    printArray(arr1, arr1_size);
  }

  //对于size小于3的数组，选择全部数据
  int arrayBegin = 0;
  int arrayEnd = size - 1;

  //对于size大于3的数组，去除前后百分之30的数据
  if(size > 3)
  {
    arrayBegin = size*0.3;
    arrayEnd = size * 0.7;
  }

  if(printlog)
  {
    Serial.print("arrayBegin: ");Serial.println(arrayBegin);
    Serial.print("arrayEnd: ");Serial.println(arrayEnd);
  }
  
  int sum = 0;
  for(int i = arrayBegin;i < arrayEnd;i++)
  {
    sum += arr1[i];
  }
  int average = sum / (arrayEnd-arrayBegin);
  if(printlog)
  {
    Serial.print("average: ");Serial.println(average);
  }
  return average;
}


void printArray(int arr1_befor[], int arr1_size_befor)
{
  for(int i = 0;i < arr1_size_befor;i++)
  {
    Serial.print(arr1_befor[i]);Serial.print(", ");
  }
  Serial.println();
}
