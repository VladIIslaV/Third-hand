# План тестирования

### Введение

Данный план описывает тестирование приложения "Third hand" для систематизации расходов.

Требования, предъявляемые к тестировщику:

* умение пользоваться устройством под управлением операционной системы Android(далее смартфон).

### Объекты тестирования

* Приложение для операционной системы Android.

Атрибуты качества приложения по ISO 25010:

* функциональность
  * функциональная полнота: приложение должно выполнять все возложенные на нее функции
  * функциональная корректность: приложение должно выполнять все возложенные на нее функции корректно
* производительность
  * временная характеристика: приложение должно открываться не медленнее чем за 30 секунд
* практичность
  * защита от ошибок пользователей: приложение должно выводить сообщения об ошибках если пользователь произвел некорректное действие
* надежность
  * доступность: приложение должно работать при автономной работе смартфомна не менее 5 минут
* мобильность
  * устанавливаемость: приложение должно корректно работать на любом смартфоне с версией Android выше 4.0 .

### Риски

При некорректной работе приложения возможен выход из строя устройства управляемого приложением.

### Аспекты тестирования

* возможность подключения по Bluetooth;
* возможность сгибания пальца Роботизированной руки;
* возможность формирования жеста Роботизированной руки;
* возможность выхода из приложения (перехода его в фоновый режим) и перехода на экран "Home";

### Подходы к тестированию

Для тестирования необходим смартфон под управлением операционной системы Android версии 4.0 и выше.

### Представление результатов

Предоставление результатов требуется описать в следующем виде:

1. Идентификатор
2. Назначение / название
3. Сценарий
4. Ожидаемый результат
5. Фактический результат (заполняется на этапе тестирования)
6. Оценка (заполняется на этапе тестирования)

Тестовые сценарии:

#### Возможность подключения по Bluetooth

1. 001

2. Проверка возможности подключения по Bluetooth

3. Произведите следующие шаги:

   1. Запустите приложение.

   2. Выберите подходящее устройство по MAC-адресу.

   3. Нажмите на кнопку "Connect".

4. Приложение выведет сообщение о подключении и отобразит окно для ввода пароля.

#### Возможность сгибания пальца.

1. 002
2. Проверка возможности сгибания пальца
3. Произведите следующие шаги:

   1. Запустите приложение.

   2. Подключитесь к подходящему устройству.

   3. Передвиньте любой ползунок.

   4. Наблюдайте за Роботизированной рукой.

####  Возможность формирования жеста

1. 003
2. Проверка возможности формирования жестов.
3. Произведите следующие шаги:

   1. Запустите приложение.

   2. Подключитесь к удалённому устройству.

   3. Нажмите на одну из 3-х кнопок жестов.

   4. Наблюдайте за роботизированной рукой.

### Вывод

Данные тесты показывают выполнение функциональных требований. Соответствие функциональных требований и тестов:

| Функциональные требования                | ID теста |
| ---------------------------------------- | :------: |
| Функция подключения по Bluetooth |    001    |
| Функция сгибания пальца |    002    |
| Функция формирования жеста |    003    |
