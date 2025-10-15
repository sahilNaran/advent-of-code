{list_1, list_2} =
  "input.txt"
  |> File.read!()
  |> String.split("\n", trim: true)
  |> Enum.map(fn line ->
    [val_1, val_2] =
      String.split(line)
      |> Enum.map(&String.to_integer/1)

    {val_1, val_2}
  end)
  |> Enum.unzip()


frequency_map = Enum.frequencies(list_2)

scores =
  Enum.map(list_1, fn val ->
    count = Map.get(frequency_map, val, 0)
    val * count
  end)
  |> Enum.sum()

IO.inspect(scores)
