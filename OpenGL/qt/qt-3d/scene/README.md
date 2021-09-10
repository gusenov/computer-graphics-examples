# Виртуальная сцена

За реализацию виртуальной сцены - показ трехмерной сцены с объектами - в Qt 3D отвечает элемент ```SceneЗD``` из модуля ```QtQuick.SceneЗD```. Все, что находится внутри сцены: 

- 3D-объекты, 
- камера, 
- свет 

все это должно быть выражено в форме *компонентов сущностей*.

Система компонентов сущностей (Entity Component System, ECS) - это популярный шаблон,
который хорошо зарекомендовал себя и получил признание в игровых движках, симуляторах
и поэтому был заимствован в Qt 3D. Ее основное преимущество - в гибкости изменения
поведения сущностей, которое может проводиться в режиме реального времени,
путем добавления либо удаления компонентов без прерывания процесса работы программы.

*Сущности* реализуются в QML элементами ```Entity```. Сама по себе сущность не несет в себе
ни поведения, ни характеристик. *Поведение* может быть добавлено к сущности путем
объединения одного или нескольких компонентов. Сущности - это, по сути, контейнеры,
в которые можно добавлять компоненты. Например, можно добавить геометрический образ
объекта и к нему добавить элемент поведения, скажем, трансформации.

Для того чтобы отобразить в трехмерной сцене элемент, его необходимо оформить в виде
сущности. Таким образом, для отображения 3D-объекта нам понадобится объединить
в элементе сущности его: 

- геометрический образ (элемент ```Mesh```), 
- материал (элемент ```Material```), дающий оболочку, 
- и трансформации (элемент ```Transform```). 

Вот, как это может выглядеть в программном коде:

```
// Объединение элементов в сущность:

Entity {
    Mesh {id: myMesh; ...}
    PhongMaterial {id: myMaterial ...}
    Transform {id: myТansform; ...}
    component: [myМesh, myMaterial, myТransform]
}
```