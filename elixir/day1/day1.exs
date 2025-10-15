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

sorted_list_1 = Enum.sort(list_1)
sorted_list_2 = Enum.sort(list_2)

total_diff =
  Enum.zip(sorted_list_1, sorted_list_2)
  |> Enum.map(fn {val_1, val_2} -> abs(val_2 - val_1) end)
  |> Enum.sum()

IO.inspect(total_diff)
