# Поток событий
## 1 Актрёры
Пользователь - человек использующий приложение.
## 2 Варианты использования
### 2.1 Подключиться к устройству 

1. Вариант использования начинается, когда пользователь включает приложение на смартфоне.
2. Приложение предлагает устройство для подключения.
3. Пользователь может выбрать другое устройство.
4. Пользователь нажимает на кнопку подключения.
5. Приложение подключается к устройству. Если нет, то вызывается альтернативный поток А1.
6. Приложение даёт пользователю понять, что готово к работе, изменяя цвет фона.
8. Вариант использования завершается.

#### Альтернативный поток А1 - Приложение переходит к началу основного потока событий.

### 2.1 Согнуть палец
Предусловие: должен выполниться вариант использования "Подключиться к устройству".

1. Вариант использования начинается, когда пользователь подключается к устройству в приложении.
2. Приложение выводит сообщение о готовности.
3. Пользователь передвигает ползунок "скролла".
4. Приложение подтверждает данное действие. Если приложение решает, что такое событие выполнить нельзя, то вызывается альтернативный поток А2.
5. Приложение генерирует сигнал и отправляет его на устройство.
6. Приложение получает ответ от устройства. Если нет, то вызывается альтернативный поток А3.
7. Приложение даёт пользователю понять, что действие выполнено полностью или частично передвигая ползунок "скролла".
8. Вариант использования завершается.

#### Альтернативный поток А2 - приложение переходит к началу основного потока событий.
#### Альтернативный поток А3 - приложение переходит к началу основного потока событий.

### 2.1 Сформировать жест
Предусловие: должен выполниться вариант использования "Подключиться к устройству".

1. Вариант использования начинается, когда пользователь подключается к устройству в приложении.
2. Приложение выводит сообщение о готовности.
3. Пользователь нажимает на кнопку одного из Жестов.
4. Приложение подтверждает данное действие. Если приложение решает, что такое событие выполнить нельзя, то вызывается альтернативный поток А4.
5. Приложение генерирует сигнал и отправляет его на устройство.
6. Приложение получает ответ от устройства. Если нет, то вызывается альтернативный поток А5.
7. Приложение даёт пользователю понять, что действие выполнено полностью или частично передвигая ползуноки "скроллов" в соответствии с происходящими действиями.
8. Вариант использования завершается.

#### Альтернативный поток А4 - приложение переходит к началу основного потока событий.
#### Альтернативный поток А5 - приложение переходит к началу основного потока событий.
