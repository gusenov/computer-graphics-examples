*Трансформация* - это изменения положения объекта вдоль любых из трех осей или плоскостей,
а также его повороты вокруг собственной оси и изменение его размеров. 

За все эти операции отвечает элемент ```Transform```, осуществляющий их с помощью свойств: 

- ```translate```
- ```rotation```
- ```scale```

```
// задаем конус с материалом
Entity {

    ConeMesh {  // Геометрия объекта
        id: coneMesh1
        topRadius: 0  // радиус верхнего основания
        bottomRadius: 1  // нижнего основания
        length: 5  // Длина конуса
        rings: 50
    }
    
    // За трансформацию конуса отвечает элемент Transform
    Transform {  // Изменение места положения
        id: coneTransform1
        
        scale: 0.5  // уменьшаем размер конуса в два раза
        
        // смещаем конус на 14 единиц в положительном направлении оси Y 
        // и на 4 единицы в положительном направлении по оси Z
        translation: Qt.vectorЗd(0, 14, 4)
        
        rotationX: 90  // поворот по оси Х на 90 градусов
    }
    
    PhongMaterial {  // Материал
        id: coneMaterial1
        diffuse: Qt.rgba( 1, 0.3, 0.2, 1 )  // Красноватый цвет
    }
    
    components: [coneMesh1, coneMaterial1, coneTransform1]
}
```