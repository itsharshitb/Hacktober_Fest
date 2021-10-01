import { createStore } from 'vuex';
import Moment from 'moment';
import CONFIG from '../global/config';
import TodoData from '../data/TodoData';

const todo = {
  namespaced: true,

  state() {
    return {
      all: TodoData.getTodo(CONFIG.TODO_STORAGE_KEY) || [],
    };
  },

  mutations: {
    setTodo(state, todo) {
      state.all = todo;
    },
  },

  actions: {
    addTodo(ctx, todo) {      
      TodoData.storeTodo(CONFIG.TODO_STORAGE_KEY, todo);
      const todoList = TodoData.getTodo(CONFIG.TODO_STORAGE_KEY);
      
      ctx.commit('setTodo', todoList);
    },

    setTodoFinished(ctx, finishedTodo) {
      const todoList = TodoData.getTodo(CONFIG.TODO_STORAGE_KEY);
      const finishedTodoIndex = todoList.findIndex((todo) => todo.id === finishedTodo.id);

      const now = Moment();

      todoList[finishedTodoIndex].finished = true;
      todoList[finishedTodoIndex].finishedAt = `${now.date()}-${now.month()}-${now.year()} ${now.hour()}:${now.minute()}`;

      TodoData.storeAllTodo(CONFIG.TODO_STORAGE_KEY, todoList)

      ctx.commit('setTodo', todoList);
    },
  },

  getters: {
    getAll(state) {
      return state.all;
    },

    getUnfinishedList(state) {
      return state.all.filter((todo) => !todo.finished);
    },
    
    getFinishedList(state) {
      return state.all.filter((todo) => todo.finished);
    },

    todoListLength(state) {
      return state.all.length;
    },
  }
};

export const store = createStore({
  modules: {
    todo,
  },
})
