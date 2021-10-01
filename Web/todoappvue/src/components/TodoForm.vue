<template>
  <form @submit.prevent="submit">
    <input
      type="text"
      placeholder="Title for what to do"
      name="title"
      v-model="title"
    />

    <textarea
      placeholder="Additional description for what to do"
      name="description"
      cols="30"
      rows="5"
      v-model="description"
    />

    <button :disabled="disabled">ADD</button>
  </form>
</template>

<script>
import { ref, reactive, computed } from 'vue';
import { useStore } from 'vuex';
import Moment from 'moment';

export default {

  setup() {
    const store = useStore();

    const title = ref('');
    const description = ref('');

    const submit = () => {
      const now = Moment();
      
      const newTodo = {
        id: store.getters['todo/todoListLength'] + 1,
        title: title.value,
        description: description.value,
        finished: false,
        createdAt: `${now.date()}-${now.month()}-${now.year()} ${now.hour()}:${now.minute()}`,
        finishedAt: '',
      };

      store.dispatch('todo/addTodo', newTodo);

      title.value = '';
      description.value = '';
    };

    const disabled = computed(() => {
      return !(title.value && description.value);
    });

    return {
      submit,
      title,
      description,
      disabled,
    }
  },

}
</script>

<style lang="scss">

@mixin input-bar {
  border: 2px solid #000000;
  border-radius: 10px;
  padding: 0 10px;
}

// Styles

form {
  width: 100%;
  margin: 0 auto;
  max-width: 500px;

  display: grid;
  grid-template-rows: auto auto auto;
  grid-template-columns: 3fr 1fr;
  gap: 10px;

  input[name="title"] {
    @include input-bar;
    font-size: 18px;
    padding: 2px 10px;
  }

  textarea[name="description"] {
    @include input-bar;
    font-size: 1rem;
    padding: 5px 10px;
    resize: none;

    grid-column-start: 1;
    grid-column-end: 3
  }

  button {
    color: #ffffff;
    font-weight: 500;
    font-size: 18px;
    background-color: #2D9CDB;
    border: none;
    border-radius: 10px;

    grid-column-start: 2;
    grid-column-end: 3;
    grid-row-start: 1;
    grid-row-end: 2;

    &:hover {
      background-color:  rgb(22, 126, 187);
    }

    &:active {
      background-color:  #2D9CDB;
    }

    &:disabled {
      background-color: #dddddd;
    }
  }
}

</style>