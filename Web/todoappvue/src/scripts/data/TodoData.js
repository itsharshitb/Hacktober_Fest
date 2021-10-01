class TodoData {
  static storeTodo(key, todo) {
    const todoList = this.getTodo(key) || [];
    todoList.push(todo);

    sessionStorage.setItem(key, this._parseObjectIntoJSON(todoList));
  }

  static storeAllTodo(key, todo) {
    sessionStorage.setItem(key, this._parseObjectIntoJSON(todo));
  }

  static getTodo(key) {
    this._checkStorage();

    return this._parseJSONIntoObject(sessionStorage.getItem(key));
  }

  static deleteTodo(key, todoTitle) {
    let todoList = this.getTodo(key);
    todoList = todoList.filter((todo) => todo.title !== todoTitle);

    sessionStorage.setItem(key, this._parseObjectIntoJSON(todoList));
  }

  static _parseObjectIntoJSON(object) {
    return JSON.stringify(object);
  }

  static _parseJSONIntoObject(jsonString) {
    return JSON.parse(jsonString);
  }

  static _checkStorage() {
    if (typeof (Storage) === 'undefined') {
      console.log('Browser doesn\'t support sessionStorage.');
      return;
    }
  }
};

export default TodoData;
