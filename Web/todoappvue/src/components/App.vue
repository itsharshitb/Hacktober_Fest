<template>
  <main>
    <todo-form />

    <h1>Todo's List</h1>
    <h3 v-if="!unfinishedTodoList.length">
      There's nothing to do right now
    </h3>

    <div v-if="unfinishedTodoList">
      <todo-item
        v-for="todo in unfinishedTodoList"
        :key="todo.id"
        :todo="todo"
        @finished="finishedHandler"
      >

        <template v-slot:title>
          #{{ todo.id }} | {{ todo.title }}
        </template>

        <template v-slot:description>
          {{ todo.description }}
        </template>

        <template v-slot:created-date>
          Created at {{ todo.createdAt }}
        </template>
      </todo-item>
    </div>

    <h1>Finished</h1>
    <h3 v-if="!finishedTodoList.length">
      There's nothing finished right now
    </h3>

    <div v-if="finishedTodoList">
      <todo-item
        v-for="todo in finishedTodoList"
        :key="todo.id"
        :todo="todo"
      >

        <template v-slot:title>
          #{{ todo.id }} | {{ todo.title }}
        </template>

        <template v-slot:description>
          {{ todo.description }}
        </template>

        <template v-slot:created-date>
          Created at {{ todo.createdAt }} | Finished at {{ todo.finishedAt }}
        </template>
      </todo-item>
    </div>
  </main>
</template>

<script>
import { computed, watchEffect } from 'vue';
import { useStore } from 'vuex';
import TodoForm from './TodoForm.vue';
import TodoItem from './TodoItem.vue';

export default {
  components: {
    TodoForm,
    TodoItem,
  },

  setup() {
    const store = useStore();

    const unfinishedTodoList = computed(() => store.getters['todo/getUnfinishedList']);
    const finishedTodoList = computed(() => store.getters['todo/getFinishedList']);
    
    const finishedHandler = (todo) => {
      store.dispatch('todo/setTodoFinished', todo);
    };

    return {
      unfinishedTodoList,
      finishedTodoList,
      finishedHandler,
    };
  },
}
</script>

<style lang="scss" scoped>

main {
  width: 100%;
  max-width: 800px;
  margin: 50px auto;
}

h1 {
  text-align: center;
  margin: 30px 0;

  & + h3 {
    font-weight: 400;
    text-align: center;
  }
}

</style>