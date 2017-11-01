# Third-hand
#   Требования к проекту
## 1 Введение
На данный момент рынок полон различными устройствами, управляющимися дистанционно. Таковые можно встретить в абсолютно разных сферах жизни. В рамках настоящего проекта реализуется приложение также необходимое для манипуляции неким устройством. Приложение "Third hand" необходимо чтобы управлять Роботизированной рукой (далее просто Рука). Оно не универсально, а заточено под устройства одной серии.
## 2 Требования
### 2.1 Программные интерфейсы

2.1.1 Qt и C++.

2.1.2 Android SDK.

2.1.3 Bluetooth libs.

### 2.2 Интерфейс пользователя
Приложение предполагает 5 элементов типа ScrollBar, расположенных в виде пальцев на кисти человека. 
![mainwindow1_1](https://user-images.githubusercontent.com/26309274/32144718-4e8dbb6c-bcce-11e7-993a-d0594d092fa7.png)

Передвигая ползунки, пользователь приложения взаимодействует с внешним устройством. Частью интерфейса также будут являться 3 кнопки, предполагающие автоматическое изменение формы устройства.
Кроме того частью интерфейса является ComboBox со списком доступных устройств и кнопку подключения к ним.

### 2.3 Характиристики пользователей
* Имеют техническое и/или медицинское образование
* Связаны с робототехникой

### 2.4 Предположения и зависимости
Разработка приложения зависит от разработки Руки. Если возникнут проблемы с разработкой второго, то не получится разработать первое.

## 3 Системные требования
Система реализуется на Qt под мобильные устройства Android и представляет из себя приложение следующего вида: содержит 5 ScrollBars и 3 Buttons, каждый ScrollBar привязан к одному конкретному пальцу так чтобы возникло 5 уникальных связок "скролл"-палец, каждая Кнопка имеет однозначную интерпретацию в виде жеста. Вся информация передаётся посредством Bluetooth.

### 3.1 Функциональные требования
Мобильное приложение:
* подключается к Руке;
* предоставляет пользователю средства для контроля физической формой устройства.

### 3.2 Нефункциональные требования
#### 3.1.1 Атрибуты качества
Главным атрибутом качества приложения является надёжность. Приложение отлавливает ситуации гонок сигналов и не даёт устройству неоднозначных команд.
#### 3.1.2 Ограничения
Масштабируемость. После модернизации устройства приложение должно корректно выполнять своё назначение.
