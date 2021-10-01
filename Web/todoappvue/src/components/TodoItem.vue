<template>

  <section>
    <h2>
      <slot name="title" />
    </h2>

    <hr>

    <p>
      <slot name="description" />
    </p>

    <p class="created-date">
      <slot name="created-date" />
    </p>

    <button
      v-if="!todo.finished"
      @click="click"
    >
      ✓
    </button>
  </section>
  
</template>

<script>
export default {
  props: {
    todo: {
      type: Object,
      required: true,
    },
  },

  setup(props, ctx) {
    const click = () => {
      ctx.emit('finished', props.todo);
    };

    return {
      click,
    }
  },
}
</script>

<style scoped lang="scss">

// Variables
$paddingTop: 30px;
$paddingBottom: 10px;
$paddingHorizontal: 40px;


// Styles
section {
  position: relative;
  width: 100%;
  min-height: 150px;
  border: 2px solid #000000;
  border-radius: 10px;
  padding: $paddingTop $paddingHorizontal $paddingBottom;
  margin-bottom: 20px;

  h2 {
    font-weight: 500;
    font-size: 18px;
  }

  hr {
    width: 100%;
    border: 1px solid #000000;
    margin: 8px 0;
  }

  p {
    font-size: 14px;
    width: calc(100% - 30px);
    margin-bottom: 50px;
    word-wrap: break-word;
    white-space: pre;
  }

  .created-date {
    margin: 0;

    position: absolute;
    left: $paddingHorizontal;
    bottom: $paddingBottom;
  }

  button {
    color: #ffffff;
    min-width: 44px;
    min-height: 44px;
    margin: 5px 0;
    border-radius: 50%;
    border: none;
    background-color: #27AE60;
    font-size: 24px;
    font-weight: bold;

    position: absolute;
    right: $paddingHorizontal;
    bottom: $paddingBottom;
  }
}

</style>